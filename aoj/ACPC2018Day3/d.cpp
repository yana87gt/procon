#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)

using Cost = int;
struct Edge{
    Cost cost;
    int to;
    bool operator>(const Edge &right)const{
        return cost > right.cost;
    }
};

int INF = 1e9;
vector<Cost> dp;

void dijkstra(vector<vector<Edge>> &g, Edge start){
    priority_queue<Edge, vector<Edge>, greater<Edge>> qu;
    dp[start.to] = start.cost;
    qu.push(start);
    while(qu.size()){
        Edge cur = qu.top();
        qu.pop();
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


int main(){
    int n;
    cin>>n;
    vector<string> s(n);

    vector<vector<Edge>> g(n);
    dp = vector<Cost>(n, INF);
    vector<int> last(26,-1);
    rep(i,n){
        cin>>s[i];
    }
    rep(i,n-1){
        g[i].push_back({1, i+1});
    }
    rep(i,n){
        int idx = (s[i][0]-'a');
        if(last[idx] != -1){
            g[last[idx]].push_back({0, i});
        }
        last[idx] = i;
    }
    dijkstra(g, (Edge){0,0});
    cout<<dp[n-1]+1<<endl;
}