#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
const int INF = 1e9;
using P = pair<ll,int>;

void dfs(int v,ll a,int signT,ll &maxT,ll &minT,
    vector<P> &visited,vector<vector<P>> &g){
    if(visited[v] != P(0,0)){
        ll b = visited[v].first;
        int sign = visited[v].second;
        if(sign==signT && a!=b) maxT = 0;
        if(sign!=signT){
            if(abs(a-b)&1) maxT = 0;
            minT = max(minT, abs(a-b)/2);
            maxT = min(maxT, abs(a-b)/2);
        }
        return;
    }
    visited[v] = {a,signT};
    if(signT == +1) minT = max(minT, 1-a);
    if(signT == -1) maxT = min(maxT, a-1);
    for(P &e : g[v]){
        ll sum = e.first;
        int to = e.second;
        dfs(to,sum-a,-signT,maxT,minT,visited,g);
    }
}

int main(void){
    int n,m;
    cin>>n>>m;
    vector<vector<P>> g(n); // <sum,to>
    rep(i,m){
        int u,v;
        ll s;
        cin>>u>>v>>s;
        u--, v--;
        g[u].push_back({s,v});
        g[v].push_back({s,u});
    }
    ll maxT = INF, minT = 0;
    vector<P> visited(n); // <a,sign> (a + sign*t)
    dfs(0,0,+1,maxT,minT,visited,g);
    cout<<max(maxT-minT+1, 0LL)<<endl;
    return 0;
}

