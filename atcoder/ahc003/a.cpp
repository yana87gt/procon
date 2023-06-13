// -------- START : snippet -------- //

#include <bits/stdc++.h>
using namespace std;

// struct IoSetup {
//     IoSetup() {
//         cin.tie(nullptr);
//         ios::sync_with_stdio(false);
//         cout << fixed << setprecision(10);
//         cerr << fixed << setprecision(10);
//     }
// } iosetup;

// -------- START : macro -------- //

#define ll long long
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)
#define rep1(i,n) for(long long i = 1; i <= (long long)(n); ++i)
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

#define ANALYZE_ 500

#define M 30
int h[30][29];
int v[29][30];
int sy,sx,ty,tx;
int a;
double e;
double score = 0;
bool local_test;

string query() {
    string path;
    if (sy < ty) {
        path += string(ty-sy, 'D');
    }
    else {
        path += string(sy-ty, 'U');
    }
    if (sx < tx) {
        path += string(tx-sx, 'R');
    }
    else {
        path += string(sx-tx, 'L');
    }

    // random
    {
        random_device seed_gen;
        mt19937 engine(seed_gen());
        shuffle(all(path), engine);
    }
    return path;
}

ll compute_path_length(string &path) {
    ll length = 0;
    int y = sy, x = sx;
    for (char &c : path) {
        if (c == 'U') {
            length += v[y-1][x];
            y--;
        }
        if (c == 'D') {
            length += v[y][x];
            y++;
        }
        if (c == 'L') {
            length += h[y][x-1];
            x--;
        }
        if (c == 'R') {
            length += h[y][x];
            x++;
        }
    }
    assert(x == tx && y == ty);
    return length;
}

int main(int argc, char *argv[]) {
    local_test = (argc >= 2 && string(argv[1]) == "local_test");
    if (local_test) {
        rep(y,M) rep(x,M-1) cin >> h[y][x];
        rep(y,M-1) rep(x,M) cin >> v[y][x];
    }
    rep1(k,1000) {
        cin >> sy >> sx >> ty >> tx;
        if (local_test) cin >> a >> e;
        string path = query();
        cout << path << endl;
        if (local_test) {
            ll b = compute_path_length(path);
            debug(a, b);
            // score += pow(0.998, 1000 - k) * a / b;
            score = score * 0.998 + a / b;
        } else {
            int point;
            cin >> point;
        }
    }
    if (local_test) {
        score = round(2312311 * score);
        cerr << fixed << setprecision(0);
        debug(score);
    }
    return 0;
}
