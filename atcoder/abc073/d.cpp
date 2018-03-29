#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e9

int N,M,R;
int edge[200][200]={};
int d[8][8];

int dfs(int mask,int v,int cost){
    if((1<<R)-1 == mask) return cost;
    int res = INF;
    rep(i,R){
        if((1<<i)&mask) continue;
        res = min(res,dfs(mask|(1<<i),i,cost+d[v][i]));
    }
    return res;
}

int main(void){
    cin>>N>>M>>R;
    vector<int> r(R);
    rep(i,R) cin>>r[i],r[i]--;
    rep(i,200) rep(j,200) edge[i][j]=(i==j ? 0 : INF);
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        edge[a][b]=c;
        edge[b][a]=c;
    }

    rep(i,N)rep(j,N)rep(k,N) edge[j][k] = min(edge[j][k], edge[j][i] + edge[i][k]);
    int res=INF;
    rep(i,R)rep(j,R) d[i][j] = edge[r[i]][r[j]];
    rep(start,R){
        res=min(res,dfs(1<<start,start,0));
    }
    cout<<res<<endl;
    return 0;
}
