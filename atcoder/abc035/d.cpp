#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<int(n);++i)
const ll INF = 1e18;

using Cost = ll;
struct Edge{
    Cost cost;
    int to;
    bool operator>(const Edge &right)const{
        return cost > right.cost;
    }
};

vector<Cost> dijkstra(vector<vector<Edge>> &g, Edge start){
    vector<Cost> dp(g.size(), (Cost)INF);
    priority_queue<Edge,vector<Edge>,greater<Edge>> qu;
    dp[start.to] = start.cost;
    qu.push(start);
    while(qu.size()){
        Edge cur = qu.top(); qu.pop();
        int v = cur.to;
        if(dp[v] < cur.cost) continue;
        for(Edge e : g[v]){
            if( dp[e.to] > cur.cost + e.cost){
                dp[e.to] = cur.cost + e.cost;
                qu.push({dp[e.to], e.to});
            }
        }
    }
    return dp;
}


int main(void){
    int n,m;
    ll T;
    cin>>n>>m>>T;
    vector<vector<Edge>> g1(n),g2(n);
    vector<ll> A(n);
    rep(i,n)cin>>A[i];
    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        g1[a].push_back({c,b});
        g2[b].push_back({c,a});
    }
    vector<Cost> dp1 = dijkstra(g1,(Edge){0,0});
    vector<Cost> dp2 = dijkstra(g2,(Edge){0,0});
    ll res = 0;
    rep(i,n){
        if (T >= (dp1[i] + dp2[i])) {
            res = max(res,(T - (dp1[i] + dp2[i])) * A[i]);
        }
    }
    cout << res << endl;
    return 0;
}
