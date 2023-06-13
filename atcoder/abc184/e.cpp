// -------- START : snippet -------- //

#include <bits/stdc++.h>
using namespace std;

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

// -------- START : macro -------- //

#define ll long long
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define len(c) (ll)c.size()
#define all(v) (v).begin(),(v).end()
#define lb(v,x) (lower_bound(all(v),x)-v.begin())
#define ub(v,x) (upper_bound(all(v),x)-v.begin())
#define has(c,x) (c.find(x) != c.end())
#define uniq(v) v.erase(unique(all(v)),v.end())
#define bit(k) (1LL<<(k))
#define INF int(1e9)

template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

// -------- END : macro -------- //

// -------- START : debug macro -------- //

template<class T,class U> ostream& operator<<(ostream& ost, const pair<T,U> &p) { ost << "(" << p.first << ", " << p.second << ")"; return ost; }
#define ostream_container { ost << "{"; for(const auto &t : v) { if (&t != &*v.begin()) ost << ", "; ost << t; } ost << "}"; return ost; }
template<class T> ostream& operator<<(ostream &ost, const vector<T> &v) ostream_container
template<class T> ostream& operator<<(ostream &ost, const set<T> &v) ostream_container
template<class T,class U> ostream& operator<<(ostream &ost, const map<T,U> &v) ostream_container

template<class H> void recursive_debug(string s, H h) {
    cerr << "\033[33m" << s << " = " << h << endl << "\033[m";
}
template<class H,class... T> void recursive_debug(string s, H h, T... t) {
    int comma = s.find(',');
    cerr << "\033[33m" << s.substr(0,comma) << " = " << h << ", ";
    recursive_debug(s.substr(comma+1), t...);
}
#define debug(...) recursive_debug(#__VA_ARGS__, __VA_ARGS__)

// -------- END : debug macro -------- //

// -------- END : snippet -------- //

int main(void) {
    int Y, X;
    cin >> Y >> X;
    vector<string> s(Y);
    rep(y,Y) cin >> s[y];
    
    int sy,sx, gy,gx;
    rep(y,Y)rep(x,X){
        if (s[y][x] == 'S') {
            sy = y, sx = x;
        }
        if (s[y][x] == 'G') {
            gy = y, gx = x;
        }
    }
    vector<vector<int>> dp(Y, vector<int>(X, INF));
    dp[sy][sx] = 0;
    using P = pair<int,int>;
    queue<P> qu;
    qu.push({sy,sx});
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    map<char, bool> warped;
    while(qu.size()) {
        P f = qu.front(); qu.pop();
        int y = f.first, x = f.second;
        rep(i,4){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= Y || nx >= X) continue;
            if (s[ny][nx] == '#') continue;
            if (dp[ny][nx] < INF) continue;
            dp[ny][nx] = dp[y][x] + 1;
            qu.push({ny, nx});
        }
        if (isalpha(s[y][x]) && !warped[s[y][x]]) {
            rep(ny,Y)rep(nx,X) {
                if (s[ny][nx] == s[y][x] && dp[ny][nx] > dp[y][x] + 1) {
                    dp[ny][nx] = dp[y][x] + 1;
                    qu.push({ny, nx});
                } 
            }
            warped[s[y][x]] = true;
        }
    }
    cout << (dp[gy][gx] == INF ? -1 : dp[gy][gx]) << endl;
    return 0;
}
