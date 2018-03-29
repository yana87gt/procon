#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,m;
    cin>>n;
    map<string,int> mp;
    rep(i,n){
        string s;
        cin>>s;
        mp[s]++;
    }
    cin>>m;
    rep(i,m){
        string t;
        cin>>t;
        mp[t]--;
    }
    int res = 0;
    for(auto p : mp){
        res = max(res, p.second);
    }
    cout<<res<<endl;
    return 0;
}
