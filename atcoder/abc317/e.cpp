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
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define rep1(i, n) for (long long i = 1; i <= (long long)(n); ++i)
#define len(c) (ll) c.size()
#define all(v) (v).begin(), (v).end()
#define lb(v, x) (lower_bound(all(v), x) - v.begin())
#define ub(v, x) (upper_bound(all(v), x) - v.begin())
#define has(c, x) (c.find(x) != c.end())
#define uniq(v) v.erase(unique(all(v)), v.end())
#define bit(k) (1LL << (k))
#define INF int(1e9)

template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}

template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}

// -------- END : macro -------- //

// -------- START : debug macro -------- //

template <class T, class U>
ostream &operator<<(ostream &ost, const pair<T, U> &p) {
    ost << "(" << p.first << ", " << p.second << ")";
    return ost;
}

#define OSTREAM_CONTAINER                   \
    ost << "{";                             \
    for (const auto &t : v) {               \
        if (&t != &*v.begin()) ost << ", "; \
        ost << t;                           \
    }                                       \
    ost << "}";                             \
    return ost;

template <class T>
ostream &operator<<(ostream &ost, const vector<T> &v) {
    OSTREAM_CONTAINER
}

template <class T>
ostream &operator<<(ostream &ost, const set<T> &v) {
    OSTREAM_CONTAINER
}

template <class T, class U>
ostream &operator<<(ostream &ost, const map<T, U> &v) {
    OSTREAM_CONTAINER
}

template <class H>
void recursive_debug(string s, H h) {
    cerr << "\033[33m" << s << " = " << h << endl << "\033[m";
}

template <class H, class... T>
void recursive_debug(string s, H h, T... t) {
    int comma = s.find(',');
    cerr << "\033[33m" << s.substr(0, comma) << " = " << h << ", ";
    recursive_debug(s.substr(comma + 1), t...);
}

#define debug(...) recursive_debug(#__VA_ARGS__, __VA_ARGS__)

// -------- END : debug macro -------- //

// -------- END : snippet -------- //

int main(void) {
    int Y, X;
    cin >> Y >> X;
    vector<string> a(Y);
    rep(y, Y) cin >> a[y];
    int sy = -1, sx = -1, gy = -1, gx = -1;
    rep(y, Y) {
        rep(x, X) {
            if (a[y][x] == 'S') {
                sy = y, sx = x;
            }
            if (a[y][x] == 'G') {
                gy = y, gx = x;
            }
            int dx = 0, dy = 0;
            if (a[y][x] == '>') {
                dx = +1;
            } else if (a[y][x] == '<') {
                dx = -1;
            } else if (a[y][x] == 'v') {
                dy = +1;
            } else if (a[y][x] == '^') {
                dy = -1;
            } else {
                continue;
            }
            int ty = y + dy, tx = x + dx;
            while (tx >= 0 && ty >= 0 && tx < X && ty < Y &&
                   (a[ty][tx] == '.' || a[ty][tx] == 'x')) {
                a[ty][tx] = 'x';
                ty += dy;
                tx += dx;
            }
        }
    }
    vector<vector<int>> d(Y, vector<int>(X, INF));
    d[sy][sx] = 0;
    using P = pair<int, int>;
    queue<P> qu;
    qu.push({sy, sx});
    int dy[] = {-1, +1, 0, 0};
    int dx[] = {0, 0, -1, +1};
    while (!qu.empty()) {
        P front = qu.front();
        qu.pop();
        int y = front.first;
        int x = front.second;
        rep(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!(nx >= 0 && ny >= 0 && nx < X && ny < Y)) continue;
            if (a[ny][nx] == '.' || a[ny][nx] == 'G') {
                chmin(d[ny][nx], d[y][x] + 1);
                a[ny][nx] = '#';
                qu.push({ny, nx});
            }
        }
    }
    cout << (d[gy][gx] == INF ? -1 : d[gy][gx]) << endl;

    return 0;
}
