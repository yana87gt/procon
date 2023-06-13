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

int n;
ll X;
vector<ll> a;
ll res = 0;

map<ll, int> give_money(ll x) {
    map<ll, int> money;
    rep(ri,n) {
        int i = n-ri-1;
        if (x >= a[i]) {
            money[a[i]] = x / a[i];
            x %= a[i];
        }
    }
    return money;
}

void dfs(int k, map<ll, int> paid, ll change) {
    // debug(k, paid, change);
    if (k == -1) {
        auto changes = give_money(change);
        rep(i,n){
            if (changes.count(a[i]) && paid.count(a[i])) return;
        }
        // debug("ok", paid, changes);
        res++;
        return;
    }
    if (change < 0) {
        if (abs(change) < a[k]) dfs(k-1, paid, change);
        paid[a[k]] = abs(change) / a[k];
        if (paid[a[k]] > 0) {
            dfs(k-1, paid, change + paid[a[k]] * a[k]);
        }
        if (abs(change) % a[k] > 0) {
            paid[a[k]]++;
            if (k < n-1 && paid[a[k]] * a[k] >= a[k+1]) return;
            dfs(k-1, paid, change + paid[a[k]] * a[k]);
        }
    } else if (change == 0) {
        res++;
    } else {
        assert(k < n-1);
        dfs(k-1, paid, change);
        if (change % a[k+1] == 0) {
            // assert(false); // ?
            return;
        }
        ll c = (a[k+1] - (change % a[k+1])) / a[k];
        if (c > 0 && c < a[k+1]/a[k]) {
            paid[a[k]] = c;
            dfs(k-1, paid, change + paid[a[k]] * a[k]);
        }
        if (c+1 < a[k+1]/a[k]) {
            paid[a[k]] = c+1;
            dfs(k-1, paid, change + paid[a[k]] * a[k]);
        }
    }
}


int main(void) {
    cin >> n >> X;
    a.resize(n);
    rep(i,n) cin >> a[i];
    dfs(n-1, {}, -X);
    cout << res << endl;
    return 0;
}
