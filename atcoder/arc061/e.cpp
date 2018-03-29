#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

typedef pair<int,int> Node; // v,com
typedef pair<int,Node> P;  // dp[Node],Node
typedef P Edge;           // int,Node

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1^(h2<<15);
    }
};

priority_queue<P,vector<P>,greater<P>> qu;
unordered_map<Node,vector<Edge>,pair_hash> g;
unordered_map<Node,int,pair_hash> dp;

int N,M;

void dijkstra(Node start){
    qu.push({dp[start]=0,start});
    while(qu.size()){
        P pr=qu.top(); qu.pop();
        Node v = pr.second;
        if(v==make_pair(N-1,-1))return;
        if(dp[v] < pr.first)continue;

        for(Edge e:g[v]){
            Node to = e.second;
            int cost = e.first;
            if(dp.count(to)==0 || dp[to] > dp[v]+cost){
                dp[to] = dp[v]+cost;
                qu.push({dp[to],to});
            }
        }
    }
}


int main(void){
    cin>>N>>M;
    rep(i,M){
        int p,q,c;
        scanf("%d %d %d",&p,&q,&c);
        p--,q--;
        if(g.count({p,c})==0){
            g[{p,c}].push_back({0,{p,-1}});
            g[{p,-1}].push_back({1,{p,c}});
        }
        if(g.count({q,c})==0){
            g[{q,c}].push_back({0,{q,-1}});
            g[{q,-1}].push_back({1,{q,c}});
        }
        g[{p,c}].push_back({0,{q,c}});
        g[{q,c}].push_back({0,{p,c}});
    }
    dijkstra({0,-1});
    cout<<(dp.count({N-1,-1}) ? dp[{N-1,-1}] : -1)<<endl;
    return 0;
}
