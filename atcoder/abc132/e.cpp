#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

const int INF = 1e9;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    g.resize(n);
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
    }
    int s,t;
    cin >> s >> t;
    s--,t--;

    vector<int> dp[3];
    rep(i,3) dp[i] = vector<int> (n, INF);
    dp[0][s] = 0;
    using P = pair<int,int>;
    queue<P> qu;
    qu.push({s,0});
    while (qu.size()) {
        P front = qu.front(); qu.pop();
        int v = front.first;
        int cost = front.second + 1;
        for(int to : g[v]){
            if (dp[cost%3][to] > cost) {
                dp[cost%3][to] = cost;
                qu.push({to, cost});
            }
        }
    }
    cout << (dp[0][t] < INF ? dp[0][t]/3 : -1) << endl;
    return 0;
}
