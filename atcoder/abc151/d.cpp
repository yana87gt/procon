#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define lb(s,x) (lower_bound(all(s),x)-s.begin())
#define ub(s,x) (upper_bound(all(s),x)-s.begin())
#define uniq(a) a.erase(unique(all(a)),a.end())
#define bit(k) (1LL<<(k))
const int INF = 1e9;

#define debug(x) cerr<<(#x)<<": "<<(x)<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

int Y, X;
vector<string> s;
int dy[4] = {-1,0,+1,0};
int dx[4] = {0,-1,0,+1};

int solve(int sy, int sx, int gy, int gx){
    using P = pair<int,int>;
    if (s[sy][sx] == '#' || s[gy][gx] == '#') return 0;
    if (sy == gy && sx == gx) return 0;
    queue<P> qu;
    vector<vector<int>> cost(Y, vector<int> (X, INF));
    qu.push({sy,sx});
    cost[sy][sx] = 0;
    int count = 0;
    while(qu.size()) {
        P top = qu.front(); qu.pop();
        int y = top.first;
        int x = top.second;
        if (y == gy && x == gx) return cost[y][x];
        rep(i,4){
            int ny = y+dy[i], nx = x+dx[i];
            if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
            if (s[ny][nx] == '#') continue;
            if (cost[ny][nx] > cost[y][x] + 1) {
                cost[ny][nx] = cost[y][x] + 1;
                qu.push({ny, nx});
            }
        }
    }
    return 0;
}

int main(void){
    cin >> Y >> X;
    s.resize(Y);
    rep(y,Y){
        cin >> s[y];
    }
    int res = 0;
    rep(sy,Y)rep(sx,X)rep(gy,Y)rep(gx,X){
        res = max(res, solve(sy,sx,gy,gx));
    }
    cout << res << endl;
    return 0;
}
