#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
const int INF = 1e9;

int dy[6] = {1,1,1,0,0,-1};
int dx[6] = {1,0,-1,1,-1,0};
#define M 410
#define D 202
bool block[M][M] = {};

int main(void){
    int n, X, Y;
    cin >> n >> X >> Y;
    X += D;
    Y += D;
    rep(i,n){
        int x,y;
        cin >> x >> y;
        x += D;
        y += D;
        block[y][x] = true;
    }
    int dp[M][M] = {};
    rep(y,M)rep(x,M) dp[y][x] = INF;
    using P = pair<int,int>;
    queue<P> qu;
    qu.push({D,D});
    dp[D][D] = 0;
    while(qu.size()) {
        int y = qu.front().first;
        int x = qu.front().second;
        qu.pop();
        rep(i,6){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= M || nx >= M || ny < 0 || nx < 0) continue;
            if (block[ny][nx]) continue;
            if (dp[ny][nx] > dp[y][x] + 1) {
                dp[ny][nx] = dp[y][x] + 1;
                qu.push({ny,nx});
            }
        }
    }
    cout << ((dp[Y][X] == INF) ? -1 : dp[Y][X]) << endl;
    return 0;
}
