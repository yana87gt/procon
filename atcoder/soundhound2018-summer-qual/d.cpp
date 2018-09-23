#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
const ll INF = 1e17;

using Cost = ll;
struct Edge{
    Cost cost;
    int to;
    bool operator>(const Edge &right)const{
        return cost > right.cost;
    }
};

const int MAX_V = 100010;

void dijkstra(vector<vector<Edge>> &g,
              vector<Cost> &dp,Edge start){
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


int main(void){
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    s--,t--;
    vector<vector<Edge>> ga(n),gb(n);
    vector<Cost> dpa(n,INF),dpb(n,INF);
    rep(i,m){
        int u,v,a,b;
        cin>>u>>v>>a>>b;
        u--,v--;
        ga[u].push_back({a,v});
        ga[v].push_back({a,u});
        gb[u].push_back({b,v});
        gb[v].push_back({b,u});
    }
    dijkstra(ga,dpa,{0,s});
    dijkstra(gb,dpb,{0,t});

    vector<Cost> vc(n);
    rep(i,n){
        vc[i] = dpa[i]+dpb[i];
    }
    reverse(all(vc));
    rep1(i,n-1){
        vc[i] = min(vc[i],vc[i-1]);
    }
    reverse(all(vc));
    const Cost kenko = 1e15;
    rep(i,n){
        cout<<kenko-vc[i]<<endl;
    }
    return 0;
}
