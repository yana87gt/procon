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

int main(void) {
    int N, M, Q;
    cin >> N >> M >> Q;
    map<pair<int,int>, int> cost;
    vector<vector<int>> g(N);
    rep(i,M){
        int a, b, c;
        cin >> a >> b >> c;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
        cost[{a,b}] = c;
    }

    vector<bool> visited(N), counted(N);
    using P = pair<int, int>;
    set<P> cand; // <cost, graph id>
    visited[0] = true;
    counted[0] = true;
    int sum = 1;
    auto get_cands = [&](int v) {
        vector<P> cands;
        for (int to : g[v]) if (!counted[to]) {
            visited[to] = true;
            cands.push_back({cost[{min(v, to), max(v, to)}], to});
        }
        return cands;
    };
    for (P p : get_cands(0)) {
        cand.insert(p);
    }

    rep(i,Q){
        int X;
        cin >> X;
        vector<P> add_cands;
        while (!cand.empty()) {
            P p = *cand.begin();
            int c = p.first;
            int v = p.second;
            if (counted[v]) {
                cand.erase(cand.begin());
            } else if (c <= X) {
                counted[v] = true;
                sum++;
                for (P pp : get_cands(v)) {
                    add_cands.push_back(pp);
                }
                cand.erase(cand.begin());
            } else {
                assert(c > X);
                break;
            }
        }
        for (P p : add_cands) {
            cand.insert(p);
        }
        cout << sum << endl;
    }
    return 0;
}
