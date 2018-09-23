#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

using P = pair<int,int>;

// ←↓→↑
int dx[4] = {-1,0,+1,0};
int dy[4] = {0,1,0,-1};
int Y,X;
vector<string> s;
vector<P> loop;
int cost[50][50];

bool space(int y, int x){
    if(!(y>=0 && x>=0 && y<Y && x<X)) return false;
    if(s[y][x] == '#') return false;
    return true;
}

void dfs(int y,int x,int dir,int depth){
    if(x==0 && y==0 && cost[0][0]) return;
    if(cost[y][x]){
        loop.push_back({cost[y][x],depth});
    }
    cost[y][x] = depth;
    for(int turn : {-1,0,+1,+2}){
        int nd = (dir+turn+4)%4;
        int ny = y + dy[nd];
        int nx = x + dx[nd];
        if(space(ny,nx)){
            dfs(ny,nx,nd,depth+1);
            return;
        }
    }
}

bool solve(){
    s.clear();
    s.resize(Y);
    loop.clear();
    rep(y,50)rep(x,50) cost[y][x] = 0;
    rep(y,Y) cin>>s[y];
    dfs(0,0,1,1);
    int corner[] = {cost[Y-1][0], cost[Y-1][X-1], cost[0][X-1]};
    rep(i,3) if(!corner[i]) return false;
    for(P lp : loop){
        rep(i,3){
            if(lp.first<=corner[i] && corner[i]<=lp.second){
                return false;
            }
        }
    }
    return true;
}

int main(void){
    while(cin>>Y>>X, Y|X){
        cout<<((solve()) ? "YES" : "NO")<<endl;
    }
    return 0;
}
