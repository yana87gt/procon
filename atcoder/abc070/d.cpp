#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

vector<pair<int,ll>> g[100010];
ll dist[100010];

void dfs(int v,int pre,ll d){
    dist[v] = d;
    for(auto to : g[v])if(pre!=to.first){
        dfs(to.first,v,d+to.second);
    }
}

int main(void){
    int N,Q,K;
    cin>>N;
    rep(i,N-1){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    cin>>Q>>K;
    dfs(K,-1,0);

    rep(i,Q){
        int x,y;
        cin>>x>>y;
        cout<<dist[x]+dist[y]<<endl;
    }
    return 0;
}
