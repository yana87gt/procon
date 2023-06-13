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
#define INF 1e18

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

using Cost = ll;
struct Edge{
    Cost cost;
    int to;
    bool operator>(const Edge &right)const{
        return cost > right.cost;
    }
};

// -------- END : snippet -------- //

int main(void) {
    int N, M;
    ll Xab, Xac, Xbc;
    cin >> N >> M >> Xab >> Xac >> Xbc;
    map<string, ll> warp_cost;
    map<char, bool> warped;
    warp_cost["AB"] = Xab;
    warp_cost["BA"] = Xab;
    warp_cost["AC"] = Xac;
    warp_cost["CA"] = Xac;
    warp_cost["BC"] = Xbc;
    warp_cost["CB"] = Xbc;
    
    string S;
    cin >> S;
    vector<vector<Edge>> g(N);
    rep(i,M) {
        int a,b;
        ll c;
        cin >> a >> b >> c;
        a--,b--;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }

    vector<Cost> dp(g.size(), (Cost)INF);
    priority_queue<Edge,vector<Edge>,greater<Edge>> qu;
    dp[0] = 0;
    qu.push({0,0});
    while(qu.size()){
        Edge cur = qu.top(); qu.pop();
        int v = cur.to;
        if(dp[v] < cur.cost) continue;
        if (!warped[S[v]]) {
            rep(i,N) {
                if (S[v] == S[i]) continue;
                string warp_string;
                warp_string += S[v];
                warp_string += S[i];
                if( dp[i] > cur.cost + warp_cost[warp_string]){
                    dp[i] = cur.cost + warp_cost[warp_string];
                    qu.push({dp[i], i});
                }
            }
            warped[S[v]] = true;
        }
        for(Edge e : g[v]){
            if( dp[e.to] > cur.cost + e.cost){
                dp[e.to] = cur.cost + e.cost;
                qu.push({dp[e.to], e.to});
            }
        }
    }
    cout << dp[N-1] << endl;
    return 0;
}
