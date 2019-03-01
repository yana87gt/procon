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

ll x[100010];
map<int,map<int,ll>> e;

int res = 0;

bool VS[100010];


void solve(int v, vector<bool> &visited, vector<>){
    visited[v] = true;
    for(auto itr : e[v]){
        int e_to = itr.first;
        ll e_cost = itr.second;

    }
}

int main(void){
    int n, m;
    cin >> n >> m;
    rep(i,n) cin >> x[i];
    rep(i,m){
        int a,b;
        ll y;
        cin >> a >> b >> y;
        e[a][b] = y;
        e[b][a] = y;
    }


    return 0;
}
