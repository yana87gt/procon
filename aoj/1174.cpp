#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)

using VII = vector<vector<int>>;

int Y,X,C;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void coloring(int y,int x,int c1,int c2,VII &s){
    if(y<0 || x<0 || x>=X || y>=Y) return;
    if(s[y][x] == c2) return;
    if(s[y][x] == c1){
        s[y][x] = c2;
        rep(i,4){
            coloring(y+dy[i],x+dx[i],c1,c2,s);
        }
    }
}

int dfs(int limit,VII cur){
    if(limit == 1){
        coloring(0,0,cur[0][0],C,cur);
        coloring(0,0,C,0,cur);
        int res = 0;
        rep(y,Y)rep(x,X){
            if(cur[y][x] == 0){
                res++;
            }
        }
        return res;
    }

    int res = 0;
    rep1(c,6)if(c != cur[0][0]){
        VII nxt = cur;
        coloring(0,0,cur[0][0],c,nxt);
        res = max(res,dfs(limit-1,nxt));
    }
    return res;
}

int main(void){
    while(cin>>Y>>X>>C, Y|X|C){
        VII s(Y);
        rep(y,Y){
            s[y].resize(X);
            rep(x,X){
                cin>>s[y][x];
            }
        }
        cout<<dfs(5,s)<<endl;
    }
    return 0;
}
