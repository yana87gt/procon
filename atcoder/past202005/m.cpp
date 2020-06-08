#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define lb(s,x) (lower_bound(all(s),x)-s.begin())
#define ub(s,x) (upper_bound(all(s),x)-s.begin())
#define uniq(a) a.erase(unique(all(a)),a.end())
#define bit(k) (1LL<<(k))
const int INF = 1e9;

#define debug(x) cerr<<(#x)<<": "<<(x)<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

using Cost = int;
struct Edge{
    Cost cost;
    int to;
    bool operator>(const Edge &right)const{
        return cost > right.cost;
    }
};

int d[20][20] = {};

int main(void){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s, k;
    cin >> s >> k;
    s--;
    vector<int> t(k+1);
    t[0] = s;
    rep1(i,k) {
        cin >> t[i];
        t[i]--;
    }
    map<int,int> mp;
    k++;
    rep(i,k) {
        mp[t[i]] = i;
    }

    
    rep(i,k){
        vector<Cost> dp(g.size(), INF);
        priority_queue<Edge,vector<Edge>,greater<Edge>> qu;
        dp[t[i]] = 0;
        qu.push({0, t[i]});
        while(qu.size()){
            Edge cur = qu.top(); qu.pop();
            int v = cur.to;
            if(dp[v] < cur.cost) continue;
            for(int to : g[v]){
                if( dp[to] > cur.cost + 1){
                    dp[to] = cur.cost + 1;
                    qu.push({dp[to], to});
                }
            }
        }
        rep(j,k){
            d[mp[t[i]]][mp[t[j]]] = dp[t[j]];
        }
    }
    vector<vector<int>> dp(1<<k);
    rep(i,1<<k) dp[i] = vector<int>(k,INF);
    dp[bit(0)][0] = 0;
    rep(mask, 1<<k) {
        rep(i,k){
            if (!(mask & bit(i))) continue;
            rep(j,k){
                if (mask & bit(j)) continue;
                if (i == j) continue;
                dp[mask|bit(j)][j] = min(dp[mask|bit(j)][j], dp[mask][i] + d[i][j]);
            }
        }
    }
    int res = INF;
    rep(i,k){
        res = min(res, dp[(1<<k)-1][i]);
    }
    cout << res << endl;

    return 0;
}
