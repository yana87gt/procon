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

#define TLE rep(i,1e9) cout << "a"
int main(void) {
    string s;
    cin >> s;
    ll x;
    cin >> x;
    int n = s.size();
    vector<ll> dp(n+1);
    int k = -1;
    rep(i,n) {
        if (isalpha(s[i])) {
            dp[i+1] = dp[i]+1;
        } else {
            dp[i+1] = dp[i] * (s[i] - '0' + 1);
        }
        if (dp[i+1] >= x) {
            k = i;
            break;
        }
    }
    while(k>=0) {
        if (dp[k+1] == x && isalpha(s[k])) {
            cout << char(s[k]) << endl;
            return 0;
        }
        if (isdigit(s[k])) {
            assert(dp[k+1] % (s[k] - '0' + 1) == 0); // true
            ll mod = (dp[k+1] / (s[k] - '0' + 1));
            // if (mod == 0) TLE;
            x %= mod;
            if (x == 0) x = mod;
        } else {
            x--;
        }
        k--;
    }
    cout << "hoge";
    return 0;
}
