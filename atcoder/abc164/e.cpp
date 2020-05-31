#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

using Cost = ll; // time
struct Edge{
    Cost cost;
    int to;
    int fee;
    bool operator>(const Edge &right)const{
        return cost > right.cost;
    }
};

#define MAX_N 50
#define MAX_C 10000
#define INF ((ll)1e16)

int main(void){
    int n, m, s;
    cin >> n >> m >> s;
    s = min(s,MAX_C);
    vector<vector<Edge>> g(n);
    rep(i,m) {
        int u, v, fee;
        Cost cost;
        cin >> u >> v >> fee >> cost;
        u--, v--;
        g[u].push_back({cost, v, fee});
        g[v].push_back({cost, u, fee});
    }
    rep(i,n) {
        int c;
        Cost d;
        cin >> c >> d;
        g[i].push_back({d, i, -c});
    }

    // 運賃 Ai <= 50, M = 100 -> 必要最高枚数 = 10000
    // dp[頂点][残り枚数] = かかった時間
    vector<vector<Cost>> dp(n);
    rep(i,n) dp[i] = vector<Cost>(MAX_C+1, INF);

    dp[0][s] = 0;
    priority_queue<Edge,vector<Edge>,greater<Edge>> qu;
    qu.push(Edge{dp[0][s], 0, s});
    while (qu.size()) {
        Edge cur = qu.top(); qu.pop();
        int v = cur.to;
        int rem = cur.fee;
        if (dp[v][rem] < cur.cost) continue;
        for (Edge e : g[v]) {
            Cost next_cost = cur.cost + e.cost;
            int next_rem = min(MAX_C, rem - e.fee);
            if (rem - e.fee >= 0 && dp[e.to][next_rem] > next_cost){
                dp[e.to][next_rem] = next_cost;
                qu.push({next_cost, e.to, next_rem});
            }
        }
    }

    vector<Cost> res(n, INF);
    rep1(i,n-1)rep(j,MAX_C+1){
        res[i] = min(res[i], dp[i][j]);
    }
    rep1(i,n-1){
        cout << res[i] << endl;
    }
    
    return 0;
}
