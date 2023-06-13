#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i,n) for(int i=0;i<int(n);++i)

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

ll com(ll n, ll r) {
    if (n < r) return 0;
    r = min(r, n-r);
    static vector<vector<ll>> c;
    if ((ll)c.size() <= n) c.resize(n+1);
    if ((ll)c[n].size() <= r) c[n].resize(r+1);
    if (c[n][r] != 0);
    else if (r == 0) c[n][r] = 1;
    else c[n][r] = com(n-1,r-1) + com(n-1,r);
    return c[n][r];
}


int main(void) {
    // ll L;
    // cin >> L;
    // cout << com(L-1, 11) << endl;
    rep(n,10)rep(r,10) {
        ll nCr = com(n,r);
        debug(n,r,nCr);
    }
    return 0;
}
