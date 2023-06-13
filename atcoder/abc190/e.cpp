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
#define INF int(1e7)

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

vector<int> shortest_path_bfs(vector<vector<int>> &graph, int start = 0, int inf = 1e7) {
    vector<int> dp(graph.size(), inf);
    queue<int> qu;
    qu.push(start);
    dp[start] = 0;
    while (!qu.empty()) {
        int cur = qu.front(); qu.pop();
        for (int to : graph[cur]) {
            if (dp[to] > dp[cur] + 1) {
                dp[to] = dp[cur] + 1;
                qu.push(to);
            }
        }
    }
    return dp;
}

// -------- END : snippet -------- //

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    rep(i,M) {
        int a,b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int K;
    cin >> K;
    vector<int> c(K);
    rep(i,K){
        cin >> c[i];
        c[i]--;
    }

    vector<vector<int>> d(K, vector<int>(K, INF));
    rep(i,K){
        auto dp = shortest_path_bfs(g, c[i], INF);
        rep(j,K) d[i][j] = dp[c[j]];
    }

    vector<vector<int>> dp(1<<K, vector<int>(K, INF));
    rep(i,K) dp[0][i] = 0;
    rep(mask,1<<K) rep(i,K) rep(j,K) chmin(dp[mask|(1<<j)][j], dp[mask][i] + d[i][j]); 

    int res = INF;
    rep(i,K) chmin(res, dp[(1<<K) -1][i]);
    cout << (res == INF ? -1 : res+1) << endl;
    return 0;
}
