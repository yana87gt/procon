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

template< typename G >
struct DoublingLowestCommonAncestor {
    const int LOG;
    vector< int > dep;
    const G &g;
    vector< vector< int > > table;

    DoublingLowestCommonAncestor(const G &g) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())) {
        table.assign(LOG, vector< int >(g.size(), -1));
    }

    void dfs(int idx, int par, int d) {
        table[0][idx] = par;
        dep[idx] = d;
        for(auto &to : g[idx]) {
            if(to != par) dfs(to, idx, d + 1);
        }
    }

    void build() {
        dfs(0, -1, 0);
        for(int k = 0; k + 1 < LOG; k++) {
            for(int i = 0; i < (int)table[k].size(); i++) {
                if(table[k][i] == -1) table[k + 1][i] = -1;
                else table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int query(int u, int v) {
        if(dep[u] > dep[v]) swap(u, v);
        for(int i = LOG - 1; i >= 0; i--) {
            if(((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
        }
        if(u == v) return u;
        for(int i = LOG - 1; i >= 0; i--) {
            if(table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }
};

// -------- END : snippet -------- //

struct Query{ int id, color, a, b, lca; };


int main(void) {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> g(N); // g[u] = {v1,v2,v3,...}
    map<pair<int,int>, int> edge; // edge[{u,v}] = edgeID
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
        edge[{a,b}] = i;
        edge[{b,a}] = i;
    }
    vector<int> par(N), depth(N);
    auto dfs = [&](auto &&f, int pre, int cur, int dep) -> void{
        par[cur] = pre;
        depth[cur] = dep;
        for (int to : g[cur]) if (pre != to) {
            f(f, cur, to, dep+1);
        }
    };
    dfs(dfs, -1, 0, 0);
    DoublingLowestCommonAncestor<vector<vector<int>>> dlca(g);
    dlca.build();
    vector<Query> query(Q+1);
    query[0] = {0, 0, 0, 0, 0};
    rep1(id,Q){
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        query[id] = {id, c, u, v, dlca.query(u, v)};
    }

    vector<int> dp(N-1); // edgeID -> queryID
    auto draw = [&](int start, int goal, int qid) {
        int cur = start;
        while (cur != goal && cur != -1) {
            int edgeID = edge[{cur,par[cur]}];
            // 既に塗られている
            if (dp[edgeID]) {
                // 今のゴールの方が上
                if (depth[goal] < depth[query[dp[edgeID]].lca]) {
                    cur = query[dp[edgeID]].lca;
                } else {
                    break;
                }
            } else {
                dp[edgeID] = qid;
                cur = par[cur];
            }
        }
    };
    rep(i,Q) {
        int qid = Q-i;
        draw(query[qid].a, query[qid].lca, qid);
        draw(query[qid].b, query[qid].lca, qid);
    }
    rep(i,N-1) {
        cout << query[dp[i]].color << endl;
    }

    return 0;
}
