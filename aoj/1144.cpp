#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e9

int X,Y;
vector<vector<int>> s;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
using P = pair<int,int>;

int solve(int y, int x, set<P> st){
    if((int)st.size() > 10) return INF;
    int res = INF;
    rep(k,4){
        int d = 1;
        while(true){
            int ny = y+d*dy[k], nx = x+d*dx[k];
            if(!(ny>=0 && nx>=0 && ny<Y && nx<X)) break;
            if(s[ny][nx] == 3) return st.size();
            if(s[ny][nx] == 1 && st.count({ny,nx})==0){
                if(d > 1){
                    st.insert({ny,nx});
                    res = min(solve(ny-dy[k],nx-dx[k],st),res);
                    st.erase({ny,nx});
                }
                break;
            }
            d++;
        }
    }
    return res;
}

int main(void){
    while(cin>>X>>Y, X|Y){
        s.clear(); s.resize(Y);
        int sy=0,sx=0;
        rep(y,Y){
            s[y].resize(X);
            rep(x,X){
                cin>>s[y][x];
                if(s[y][x] == 2) sy = y, sx = x;
            }
        }
        int res = solve(sy,sx,{{sy,sx}});
        cout<<(res>10 ? -1 : res)<<endl;
    }
    return 0;
}
