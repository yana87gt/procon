#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define INF 1e9

struct state{
    int cost,y,x,dir;
    bool operator>(const state &right)const{
        return cost > right.cost;
    }
};

//           →↓←↑
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int X,Y;
int s[30][30];
int dp[30][30][4];
int c[4]; // straight, right, back, left, halt

void dijkstra(){
    using P = state;
    priority_queue<P,vector<P>,greater<P>> qu;
    qu.push({dp[0][0][0] = 0, 0,0,0});
    while(qu.size()){
        P cur = qu.top(); qu.pop();
        int y = cur.y;
        int x = cur.x;
        int dir = cur.dir;
        if(y == Y-1 && x == X-1) return;
        if(dp[y][x][dir] < cur.cost) continue;
        rep(i,4){
            int nd = (dir+i)%4;
            int ny = y + dy[nd];
            int nx = x + dx[nd];
            int cost = (i==s[y][x] ? 0 : c[i]);
            if(ny<0 || nx<0 || nx>=X || ny>=Y) continue;
            if( dp[ny][nx][nd] > dp[y][x][dir] + cost){
                dp[ny][nx][nd] = dp[y][x][dir] + cost;
                qu.push({dp[ny][nx][nd],ny,nx,nd});
            }
        }
    }
}

int main(void){
    while(cin>>X>>Y, X|Y){
        rep(y,30)rep(x,30)rep(i,4){
            dp[y][x][i] = INF;
        }
        rep(y,Y) rep(x,X) cin>>s[y][x];
        rep(i,4) cin>>c[i];
        dijkstra();
        int res = INF;
        rep(i,4){
            res = min(res, dp[Y-1][X-1][i]);
        }
        cout<<res<<endl;
    }
    return 0;
}
