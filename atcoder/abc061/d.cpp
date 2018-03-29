#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define INF 1e16
typedef long long ll;
typedef pair<ll,int> edge;
vector<edge> g[1000];
ll dp[1000];
bool usedV[1000];
map<pair<int,int>,bool> usedE;

int main(void){
    int n,m;
    cin>>n>>m;
    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        --a,--b;
        g[a].push_back({c,b});
    }

    priority_queue<edge,vector<edge>> pq;
    pq.push({dp[0]=0,0});
    while(pq.size()){
        edge pr = pq.top(); pq.pop();
        int from = pr.second;
        if(usedV[from] && pr.first < dp[from]) continue;
        for(edge e : g[from]){
            ll cost = e.first;
            int to = e.second;
            if(dp[to] >= INF) continue;
            if(!usedV[to] || dp[to] < dp[from]+cost){
                dp[to] = (usedE[{from,to}] ? INF : dp[from]+cost);
                pq.push({dp[to],to});
                usedV[to] = true;
                usedE[{from,to}] = true;
            }
        }
    }
    if(dp[n-1] >= INF) cout<<"inf"<<endl;
    else cout<<dp[n-1]<<endl;
    return 0;
}
