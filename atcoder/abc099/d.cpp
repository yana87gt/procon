#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define INF 1e9

int main(void){
    int N,C;
    cin>>N>>C;
    int d[31][31] = {};
    int c[3][31] = {};
    rep1(x,C)rep1(y,C) cin>>d[x][y];
    rep1(i,N)rep1(j,N){
        int color;
        cin>>color;
        c[(i+j)%3][color]++;
    }
    int cost[3][31] = {};
    rep(i,3)rep1(x,C)rep1(y,C){
        cost[i][y] += c[i][x]*d[x][y];
    }
    int res = INF;
    rep1(i,C)rep1(j,C)rep1(k,C){
        if(i==j || j==k || k==i) continue;
        res = min(res, cost[0][i]+cost[1][j]+cost[2][k]);
    }
    cout<<res<<endl;
    return 0;
}
