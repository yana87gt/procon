#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
const int INF = 1e9;

struct Point{ int y,x; };

int dy[4] = {-1,0,+1,0};
int dx[4] = {0,1,0,-1};

int main(void){
    int Y, X, K;
    cin >> Y >> X >> K;
    int sx,sy, gx,gy;
    cin >> sy >> sx >> gy >> gx;
    sx--,sy--,gx--,gy--;
    vector<string> s(Y);
    rep(y,Y) cin >> s[y];

    vector<vector<int>> dp(Y, vector<int>(X, INF));
    dp[sy][sx] = 0;
    queue<Point> qu;
    qu.push({sy,sx});
    while(qu.size()) {
        Point p = qu.front(); qu.pop();
        rep(dir,4){
            rep1(k,K){
                int ny = p.y + dy[dir]*k;
                int nx = p.x + dx[dir]*k;
                if (ny < 0 || nx < 0 || ny >= Y || nx >= X) break;
                if (s[ny][nx] == '@') break;
                if (dp[ny][nx] <= dp[p.y][p.x]) break;
                if (dp[ny][nx] > dp[p.y][p.x] + 1) {
                    dp[ny][nx] = dp[p.y][p.x] + 1;
                    qu.push({ny,nx});
                }
            }
        }
    }
    cout << ((dp[gy][gx] == INF) ? -1 : dp[gy][gx]) << endl;
    return 0;
}
