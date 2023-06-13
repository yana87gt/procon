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

int dp[1<<16][16];

int main(void) {
    rep(i, 1<<16) rep(j,16) dp[i][j] = -2;
    int Y, X;
    cin >> Y >> X;
    vector<string> s(Y);
    rep(y,Y) cin >> s[y];
    rep(y,Y)rep(x,X) {
        int id = y*Y+x;
        if (s[y][x] == '#') {
            dp[1<<id][id] = -1;
        }
    }
    pair<int,int> res = {0,0};

    rep(mask, 1<<(Y*X)) {
        rep(last, Y*X) if ((mask >> last) & 1) {
            if (dp[mask][last] == -2) continue;
            int x = last % Y, y = last/Y;
            if (s[y][x] != '#') continue;
            int nid;
            nid = (y-1)*Y+x;
            if (y > 0 && s[y-1][x] == '#' && !(mask & (1<<nid))) {
                dp[mask | (1<<nid)][nid] = last;
            }

            nid = (y+1)*Y+x;
            if (y < Y-1 && s[y+1][x] == '#' && !(mask & (1<<nid))) {
                dp[mask | (1<<nid)][nid] = last;
            }

            nid = y*Y+x-1;
            if (x > 0 && s[y][x-1] == '#' && !(mask & (1<<nid))) {
                dp[mask | (1<<nid)][nid] = last;
            }

            nid = y*Y+x+1;
            if (x < X-1 && s[y][x+1] == '#' && !(mask & (1<<nid))) {
                dp[mask | (1<<nid)][nid] = last;
            }
            if (__builtin_popcount(res.first) < __builtin_popcount(mask)) {
                res = {mask, last};
            }
        }
    }
    cout << __builtin_popcount(res.first) << endl;
    int id = res.second;
    int mask = res.first;
    while(mask) {
        cout << (id/Y)+1 << " " << (id%Y)+1 << endl;
        int pid = dp[mask][id];
        mask ^= 1<<id;
        id = pid;
    }

    return 0;
}
