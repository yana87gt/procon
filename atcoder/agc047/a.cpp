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

pair<ll, ll> product_2_5(ll x) {
    ll p2 = 0, p5 = 0;
    while (x % 2 == 0) {
        x /= 2;
        p2++;
    }
    while (x % 5 == 0) {
        x /= 5;
        p5++;
    }
    return {p2, p5};
}
// -------- END : snippet -------- //

int main(void) {
    ll n;
    cin >> n;
    map<pair<ll, ll>, ll> mp;
    ll res = 0;
    rep(i,n) {
        string s;
        cin >> s;
        int pos = s.find('.');
        pair<ll, ll> bunsi, bunbo;
        if (pos != -1) {
            bunbo = {s.size() - pos - 1, s.size() - pos -1};
            s.erase(pos, 1);
            bunsi = product_2_5(stoll(s));
        } else {
            bunsi = product_2_5(stoll(s));
        }
        pair<ll, ll> p25 = {bunsi.first - bunbo.first, bunsi.second - bunbo.second};
        for (auto itr : mp) {
            pair<ll, ll> mp25 = itr.first;
            if (mp25.first + p25.first >= 0 && mp25.second + p25.second >= 0) {
                res += itr.second;
            }
        }
        mp[p25]++;
    }
    cout << res << endl;
    return 0;
}
