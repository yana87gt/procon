#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int H,W;
    int c[10][10],a[200][200];
    cin>>H>>W;
    rep(i,10)rep(j,10)cin>>c[i][j];
    rep(y,H)rep(x,W)cin>>a[y][x];
    rep(i,10)rep(j,10)rep(k,10) c[j][k] = min(c[j][k],c[j][i]+c[i][k]);
    
    int cost = 0;
    rep(y,H)rep(x,W){
        if(a[y][x] != -1){
            cost += c[a[y][x]][1];
        }
    }
    cout<<cost<<endl;
    return 0;
}
