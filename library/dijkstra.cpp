///
/// for vscode snippet
/// prefix: lib-dijkstra
///

using Cost = int;
struct Edge{
    Cost cost;
    int to;
    bool operator>(const Edge &right)const{
        return cost > right.cost;
    }
};

void dijkstra(vector<vector<Edge>> &g, Edge start){
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
}
