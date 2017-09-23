#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

vector<pair<int,int>> v;
int n,m;

bool check(int x,int k){
    multiset<int> absent;
    int pre = 0;
    int last = -1;
    int idx = 0;
    while(pre+x < m+1){
        int d = pre+x;
        while(idx<n && v[idx].first<=d){
            absent.insert(v[idx].second);
            ++idx;
        }

        auto itr = absent.upper_bound(pre);
        if(itr == absent.end()){
            if(k==0 || last<=pre) return false;
            --k;
            pre = last;
            last = -1;
        }else{
            last = max(last,*itr);
            pre = min(d,*itr);
            absent.erase(itr);
        }
    }
    return true;
}


int main(){
    int k;
    cin>>n>>m>>k;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());

    int l=0, r=m+1;
    while(l+1<r){
        int x=(l+r)/2;
        if(check(x,k)) r = x;
        else l = x;
    }
    cout<<r<<endl;

    return 0;
}