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

template <typename T>
class SegmentTree{
  public:
    int n;
    T element;
    vector<T> dat;
    function<T(T,T)> operate;

    SegmentTree(){}
    SegmentTree(int n_,T element_,function<T(T,T)> operate_){
        element = element_;
        operate = operate_;
        n = 1;
        while(n < n_) n *= 2;
        dat = vector<T>(n*2,element);
    }

    void update(int k,T a){
        k += n-1;
        dat[k] = a;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = operate(dat[k*2+1],dat[k*2+2]);
        }
    }

    T query(int a,int b,int k,int l,int r){
        if(r<=a || b<=l) return element;
        if(a<=l && r<=b) return dat[k];
        T vl = query(a,b,k*2+1,l,(l+r)/2);
        T vr = query(a,b,k*2+2,(l+r)/2,r);
        return operate(vl,vr);
    }

    T query(int a,int b) { return query(a,b,0,0,n); }

    T get(int k){ return query(k,k+1); }

    friend ostream& operator<<(ostream& ost, SegmentTree<T> &seg){
        vector<T> res;
        rep(i,seg.n) ost << seg.get(i) << ", ";
        return ost;
    }

};

// -------- END : snippet -------- //

struct Gas{
    ll cost;
    int limit;
    bool operator>(const Gas &right)const{
        return cost > right.cost;
    }
};

// a.cost > b.cost && a.limit > b.limit -> どちらも生かす
// a.cost > b.cost && a.limit <= b.limit -> a いらない

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--, b--;
    vector<ll> c(n);
    vector<vector<int>> g(n);
    rep(i,n) {
        int par;
        cin >> par >> c[i];
        if (par == 0) continue;
        par--;
        g[i].push_back(par);
        g[par].push_back(i);
    }

    // a->b のパスを main branch とする
    vector<bool> is_main(n);
    auto check_main = [&](auto &&f, int cur, int pre) -> bool {
        if (cur == b) return is_main[cur] = true;
        for (int to : g[cur]) if (to != pre) {
            if (f(f, to, cur)) is_main[cur] = true;
        }
        return is_main[cur];
    };
    check_main(check_main, a, -1);
    // debug(is_main);

    SegmentTree<ll> seg(n+m, 1e18, [](ll a, ll b){ return min(a,b);});
    seg.update(m, 0);
    // debug(seg);
    ll res = 1e18;
    // depth: main branch の深さ
    // dist: main branch からの距離
    auto dfs = [&](auto f, int cur, int pre, int depth, int dist) -> void {
        if (cur == b) {
            res = seg.query(depth, n+m);
            if (res >= 1e18) res = -1;
        }
        // debug(cur, pre, depth , dist , c[cur]);
        if (dist >= m) return;
        if (c[cur]) seg.update(depth + m - dist, min(seg.get(depth + m - dist), seg.query(depth + dist, n+m) + c[cur]));
        int to_main = -1;
        // debug(__LINE__);
        for (int to : g[cur]) if (to != pre) {
            // debug(__LINE__);
            if (is_main[to]) {
                to_main = to;
                continue;
            }
            f(f, to, cur, depth, dist+1);
        }
        // debug(__LINE__);
        if (to_main != -1) {
            f(f, to_main, cur, depth+1, 0);
        }
    };
    dfs(dfs, a, -1, 0, 0);
    cout << res << endl;
}


int main(void) {
    int T;
    cin >> T;
    rep(t,T) {
        printf("Case #%d: ", t+1);
        solve();
        // {
        //     int n, m, a, b;
        //     cin >> n >> m >> a >> b;
        //     if (t+1 == 17) cout << n << " "<< m << " " << a << " " << b << endl;
        //     rep(i,n) {
        //         ll par, c;
        //         cin >> par >> c;
        //         if (t+1 == 17) cout << par << " " << c << endl;
        //     }
        // }
    }
    return 0;
}
