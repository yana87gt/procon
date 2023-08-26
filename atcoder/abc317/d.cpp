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
#define INF (ll)1e18

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
    int N;
    cin >> N;
    vector<ll> x(N), y(N), z(N);
    rep(i, N) cin >> x[i] >> y[i] >> z[i];
    vector<ll> weight(N);
    rep(i, N) weight[i] = max((x[i] + y[i] + 1) / 2 - x[i], 0LL);
    ll Z = accumulate(all(z), 0);
    vector<ll> dp(Z + 1, INF);
    dp[0] = 0;
    rep(i, N) {
        for (int j = Z; j >= 0; j--) {
            if (dp[j] < INF) {
                chmin(dp[j + z[i]], dp[j] + weight[i]);
            }
        }
    }
    ll res = INF;
    for (int i = (Z + 1) / 2; i <= Z; i++) {
        chmin(res, dp[i]);
    }
    cout << res << endl;

    return 0;
}
