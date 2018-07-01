#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int Y,X;
    while(cin>>Y>>X, Y|X){
        int e[10][10] = {};
        rep(y,Y)rep(x,X) cin>>e[y][x];
        int res = 0;
        rep(y2,Y)rep(y1,y2-1)rep(x2,X)rep(x1,x2-1){
            int mn = 9, sum = 0, mx = 0;
            for(int y = y1; y<=y2; y++)for(int x = x1; x<=x2; x++){
                if(x==x1 || x==x2 || y==y1 || y==y2){
                    mn = min(mn,e[y][x]);
                }else{
                    mx = max(mx,e[y][x]);
                    sum += e[y][x];
                }
            }
            if(mn > mx){
                res = max(res, mn*(y2-y1-1)*(x2-x1-1) - sum);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
