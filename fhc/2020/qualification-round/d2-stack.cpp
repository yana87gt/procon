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

#define ll long long
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF (ll)(1e18)

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
};

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
    struct State {
        bool evaluatable;
        int cur, pre, depth, dist;
    };
    stack<State> stack;
    stack.push({false, a, -1});
    
    while (!stack.empty()) {
        State state = stack.top(); stack.pop();
        bool evaluatable = state.evaluatable;
        int cur = state.cur, pre = state.pre;
        if (evaluatable) {
            for (int to : g[cur]) if (to != pre) {
                if (is_main[to]) is_main[cur] = true;
            }
        } else if (cur == b) {
            is_main[cur] = true;
        } else {
            stack.push({true, cur, pre});
            for (int to : g[cur]) if (to != pre) {
                stack.push({false, to, cur});
            }
        }
    }

    SegmentTree<ll> seg(n+m, INF, [](ll a, ll b){ return min(a,b);});
    seg.update(m, 0);
    ll res = INF;
    // depth: main branch の深さ
    // dist: main branch からの距離
    stack.push({true, a, -1, 0, 0});
    while (!stack.empty()) {
        State state = stack.top(); stack.pop();
        int cur = state.cur, pre = state.pre, depth = state.depth, dist = state.dist;
        if (dist >= m) continue;
        if (cur == b) {
            res = seg.query(depth, n+m);
            if (res >= INF) res = -1;
            break;
        }
        if (c[cur]) seg.update(depth + m - dist, min(seg.get(depth + m - dist), seg.query(depth + dist, n+m) + c[cur]));
        for (int to : g[cur]) if (to != pre) {
            if (is_main[to]) {
                stack.push({true, to, cur, depth+1, 0});
            }
        }
        for (int to : g[cur]) if (to != pre) {
            if (!is_main[to]) {
                stack.push({true, to, cur, depth, dist+1});
            }
        }
    }
    cout << res << endl;
}

int main(void) {
    int T;
    cin >> T;
    rep(t,T) {
        printf("Case #%d: ", t+1);
        solve();
    }
    return 0;
}
