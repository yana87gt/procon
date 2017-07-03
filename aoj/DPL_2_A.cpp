#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
const int MAX_V = 15;
const int INF = 1e9;
 
int V,E;
int d[MAX_V][MAX_V];
int dp[1<<MAX_V][MAX_V];

//bitDP
//ある頂点vから出発し、各頂点１回ずつ通ってvに戻ってくる（オイラー路）
// = 頂点0から出発し、回りきった最後の頂点から0に戻ってくる

int dfs(int mask,int v){
    if(mask==(1<<V)-1) return d[v][0];
    if(dp[mask][v]!=-1) return dp[mask][v];
    int res = INF;
    rep(u,V){
        if(d[v][u]==INF || (mask&(1<<u))) continue;
        res = min(res, dfs(mask|(1<<u),u)+d[v][u]);
    }
    return dp[mask][v] = res;
}

int main() {
    cin>>V>>E;
    rep(i,V)rep(j,V) d[i][j]=INF;
    rep(i,V) d[i][i]=0;
    rep(i,E){
        int s,t;
        cin>>s>>t;
        cin>>d[s][t];
    }
    memset(dp, -1, sizeof(dp));
    int res=dfs(1,0);
    cout<<(res==INF ? -1 : res)<<endl;
    return 0;
}