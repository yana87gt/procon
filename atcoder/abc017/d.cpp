#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
const int mod = 1e9+7;

int main(void){
    int n,m;
    cin>>n>>m;
    vector<int> f(n+1);
    vector<set<int>> fsame(m+1);
    rep1(i,m) fsame[i].insert(0);
    rep1(i,n){
        cin>>f[i];
        fsame[f[i]].insert(i);
    }

    vector<int> dp(n+1);
    int seg=dp[0]=1, l=0;
    rep1(i,n){
        auto itr = fsame[f[i]].find(i);
        --itr;
        while(l < (*itr)){
            seg = (seg+mod-dp[l])%mod;
            l++;
        }
        dp[i] = seg;
        seg = (seg*2)%mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}
