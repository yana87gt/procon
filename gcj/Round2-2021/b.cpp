// -------- START : snippet -------- //

#include <bits/stdc++.h>
using namespace std;

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

int f(int n, bool first) {
    if (n == 1) return 0;
    int mx = 0;
    for (int d = (first ? 3 : 2); d < n; d++) {
        if (n % d == 0) {
            chmax(mx, f(n/d - 1, false));
        }
    }
    return 1 + mx;
}

int main(void) {
    int T;
    cin >> T;
    rep(testcase, T){
        cout << "Case #" << testcase + 1 << ": ";
        int N;
        cin >> N;
        cout << f(N, true) << endl;
    }
    return 0;
}