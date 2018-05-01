#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e9
struct Edge{int a,b,c;};

int main(void){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    int d[n][n];
    rep(i,n)rep(j,n) d[i][j] = INF;
    rep(i,n) d[i][i] = 0;

    vector<Edge> ve;
    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        d[a][b] = d[b][a] = c;
        ve.push_back({a,b,c});
    }
    rep(k,n)rep(i,n)rep(j,n){
        if( d[i][j] > d[i][k] + d[k][j]){
            d[i][j] = d[i][k] + d[k][j];
        }
    }
    int cnt = 0;
    for(auto e : ve){
        bool use = false;
        rep(s,n)rep(t,n)if(s!=t){
            if(d[s][t] == d[s][e.a] + e.c + d[e.b][t]){
                use = true;
            }
        }
        if(!use) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
