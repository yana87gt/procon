#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int n,m;
bool g[8][8];

int dfs(int v,int mask){
    if((1<<n)-1 == mask){
        return 1;
    }
    int sum = 0;
    rep(u,n){
        if(!g[v][u] || mask&(1<<u))continue;
        sum += dfs(u,mask|(1<<u));
    }
    return sum;
}

int main(void){
    cin>>n>>m;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a][b] = true;
        g[b][a] = true;
    }
    cout<<dfs(0,1)<<endl;
    return 0;
}
