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

int main(void) {
    int D, G;
    cin >> D >> G;
    G /= 100;
    vector<int> p(D + 1), c(D + 1);
    rep1(i, D) {
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }
    int M = 110000;
    vector<int> dp(M + 1, INF);
    dp[0] = 0;
    rep1(i, D) {
        for (int s = M; s >= 0; s--) {
            if (dp[s] == INF) continue;
            rep1(j, p[i] - 1) { chmin(dp[s + i * j], dp[s] + j); }
            chmin(dp[s + i * p[i] + c[i]], dp[s] + p[i]);
        }
    }
    int res = INF;
    rep(s, M) {
        if (s >= G) {
            chmin(res, dp[s]);
        }
    }
    cout << res << endl;
    return 0;
}