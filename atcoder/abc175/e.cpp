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

ll dp[3010][3010][4] = {};
ll cost[3010][3010] = {};

int main(void) {
    int Y, X, K;
    cin >> Y >> X >> K;
    rep(i,K){
        int y, x;
        ll v;
        cin >> y >> x >> v;
        y--,x--;
        cost[y][x] = v;
    }
    dp[0][0][0] = 0;
    dp[0][0][1] = cost[0][0];
    rep(y,Y) {
        rep(x,X) {
            if (y > 0) {
                dp[y][x][0] = max({dp[y-1][x][0], dp[y-1][x][1], dp[y-1][x][2], dp[y-1][x][3]});
                dp[y][x][1] = dp[y][x][0] + cost[y][x];
            }
            if (x > 0) {
                chmax(dp[y][x][0], dp[y][x-1][0]);
                chmax(dp[y][x][1], max({dp[y][x-1][1], dp[y][x-1][0] + cost[y][x]}));
                chmax(dp[y][x][2], max({dp[y][x-1][2], dp[y][x-1][1] + cost[y][x]}));
                chmax(dp[y][x][3], max({dp[y][x-1][3], dp[y][x-1][2] + cost[y][x]}));
            }
        }
    }
    cout << max({dp[Y-1][X-1][0], dp[Y-1][X-1][1], dp[Y-1][X-1][2], dp[Y-1][X-1][3]}) << endl;
    return 0;
}
