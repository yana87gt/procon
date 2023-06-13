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

int main(void) {
    int N, Q;
    cin >> N >> Q;
    vector<ll> h(N);
    rep(i,N) cin >> h[i];
    map<ll, int> diff[2];
    ll common[2] = {};
    // 0: h[1]-h[0], h[3]-h[2], ... 
    // 1: h[2]-h[1], h[4]-h[3], ... 
    rep(i,N-1){
        diff[i % 2][h[i+1] - h[i]]++;
    }

    rep(q, Q) {
        int t;
        cin >> t;
        if (t == 1) {
            int v;
            cin >> v;
            common[0] -= v;
            common[1] += v;
        }
        if (t == 2) {
            int v;
            cin >> v;
            common[0] += v;
            common[1] -= v;
        }
        if (t == 3) {
            int u, v;
            cin >> u >> v;
            u--;
            if (u>0) {
                diff[(u-1)%2][h[u] - h[u-1]]--;
                diff[(u-1)%2][(h[u]+v) - h[u-1]]++;
            }
            if (u<N-1) {
                diff[u%2][h[u+1] - h[u]]--;
                diff[u%2][h[u+1] - (h[u]+v)]++;
            }
            h[u] += v;
        }
        cout << diff[0][-common[0]] + diff[1][-common[1]] << endl;
    }
    return 0;
}
