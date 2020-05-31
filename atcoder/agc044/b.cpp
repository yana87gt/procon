#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int main(void){
    int n;
    cin >> n;
    vector<vector<int>> d(n);
    vector<vector<bool>> space(n);
    rep(y,n) {
        d[y] = vector<int>(n);
        space[y] = vector<bool>(n);
    }
    rep(y,n) rep(x,n) {
        d[y][x] = min({y, n-y-1, x, n-x-1});
    }
    int sum = 0;
    rep(i,n*n) {
        int p;
        cin >> p;
        p--;
        int y = p/n;
        int x = p%n;
        sum += d[y][x];
        space[y][x] = true;
        using P = pair<int,int>;
        queue<P> qu;
        qu.push({y,x});
        while(qu.size()) {
            int cy = qu.front().first;
            int cx = qu.front().second;
            qu.pop();
            int cost = space[cy][cx] ? 0 : 1;
            rep(dir,4){
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if (ny >= n || nx >= n || ny < 0 || nx < 0) continue;
                if (d[ny][nx] > d[cy][cx] + cost) {
                    d[ny][nx] = d[cy][cx] + cost;
                    qu.push({ny, nx});
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
