#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    rep(i,n){
        int a;
        cin>>a;
        mp[a]++;
    }
    vector<int> v;

    for(auto x : mp){
        v.push_back(x.second);
    }
    sort(all(v));
    int m = v.size();
    int sum = 0;
    rep(i,m-k){
        sum += v[i];
    }
    cout<<sum<<endl;

    return 0;
}
