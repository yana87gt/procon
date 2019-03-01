#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

vector<vector<int>> g;
vector<int> dp;

int rec(int v){
    if (dp[v]) return dp[v];
    for(int to : g[v]){
        dp[v] = max(dp[v], rec(to)+1);
    }
    return dp[v];
}

int main(void){
    int n,m;
    cin >> n >> m;
    g.resize(n);
    dp.resize(n);
    rep(i,m){
        int x,y;
        cin >> x >> y;
        x--,y--;
        g[y].push_back(x);
    }
    int res = 0;
    rep(i,n) res = max(res,rec(i));
    cout << res << endl;
    return 0;
}
