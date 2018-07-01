#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
int n,k,q;
int res = 1e9;
vector<int> a;

void solve(int x){
    vector<int> s;
    priority_queue<int,vector<int>,greater<int>> qu;
    rep(i,n+1){
        if(a[i] < x){
            while(!qu.empty()){
                if(qu.size() >= k){
                    s.push_back(qu.top());
                }
                qu.pop();
            }
        }else{
            qu.push(a[i]);
        }
    }
    if(s.size() < q) return;
    sort(s.begin(), s.end());
    res = min(res, s[q-1]-x);
}

int main(void){
    cin>>n>>k>>q;
    a.resize(n);
    rep(i,n) cin>>a[i];
    a.push_back(0);
    rep(i,n) solve(a[i]);
    cout<<res<<endl;
    return 0;
}
