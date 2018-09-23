#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define FOR(i,l,r) for(int i=l;i<r;++i)

int main(void){
    int X,Y,T,P;
    while(cin>>X>>Y>>T>>P, X|Y|T|P){
        vector<vector<int>> s(2500, vector<int>(2500, 0));
        int x1 = 0, y1 = 0, x2 = X, y2 = Y;
        rep(y,Y) rep(x,X) s[y][x] = 1;
        rep(_,T){
            int d,c;
            cin>>d>>c;
            if(d == 1){
                rep(i,c){
                    FOR(y, y1, y2){
                        int rx = x1+c*2-1-i;
                        s[y][rx] += s[y][x1+i];
                        s[y][x1+i] = 0;
                    }
                }
                x2 = max(x2, x1+2*c);
                x1 += c;
            }else{
                FOR(x, x1, x2){
                    rep(i,c){
                        int uy = y1+c*2-1-i;
                        s[uy][x] += s[y1+i][x];
                        s[y1+i][x] = 0;
                    }
                }
                y2 = max(y2, y1+2*c);
                y1 += c;
            }
        }
        rep(_,P){
            int x,y;
            cin>>x>>y;
            cout<<s[y1+y][x1+x]<<endl;
        }
    } 
    return 0;
}
