#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int dfs(int v, vector<set<int>> &g, vector<int> &dp){
    if(v == 0) return 0;
    if(dp[v]) return dp[v];
    int res = dfs(v-1,g,dp);
    for(int to : g[v]){
        res = max(res,v-to + dfs(to,g,dp));
    }
    return dp[v] = res;
}

int main(void){
    int n;
    while(cin>>n, n){
        vector<int> w(n+1);
        rep1(i,n) cin>>w[i];
        w[0] = -1;

        // i番目が消える時に右側に会わせられるブロックのindexの集合
        vector<set<int>> g(n+1);
        rep1(i,n){
            if(abs(w[i]-w[i-1]) <= 1){
                g[i] = g[i-2];
                g[i].insert(i-2);
            }
            for(int l : g[i-1]){
                if(abs(w[i]-w[l]) <= 1){
                    for(int ll : g[l-1]){
                        g[i].insert(ll);
                    }
                    g[i].insert(l-1);
                }
            }
        }
        vector<int> dp(n+1);
        cout<<dfs(n,g,dp)<<endl;
    }
    return 0;
}
