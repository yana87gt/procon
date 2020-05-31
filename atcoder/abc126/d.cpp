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

using Edge = pair<int,ll>;

vector<Edge> g[100010];
int color[100010];

void coloring(int pre, int v, ll dist) {
    color[v] = dist%2;
    for(Edge e : g[v]){
        int to = e.first;
        ll d = e.second;
        if (to == pre) continue;
        coloring(v, to, dist + d);
    }
}

int main(void){
    int n;
    cin >> n;
    rep(i,n-1){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    coloring(-1, 0, 0);
    rep(i,n){
        cout << color[i] << endl;
    }

    return 0;
}
