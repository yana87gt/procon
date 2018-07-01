#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

using P = pair<ll,int>; // price, 在庫

int n,m;

const int MAX_V = 5010;
vector<int> g[MAX_V];
vector<pair<int,P>> shop; // <,<proce,zaiko>>
vector<int> dp;

void dijkstra(int start){
    dp = vector<int>(n, INF);
    queue<int> qu;
    dp[start] = 0;
    qu.push(start);
    while(qu.size()){
        int v = qu.front(); qu.pop();
        for(int to:g[v]) if(dp[to] == INF){
            dp[to] = dp[v]+1;
            qu.push(to);
        }
    }
}

bool possible(int x, ll r, ll a){
    ll cost = 0;
    ll count = 0;
    for(auto &pp : shop) if(dp[pp.second.first] <= x){
        P s = {pp.first, pp.second.second};
        int want = min<ll>(s.second, r - count);
        if(cost + s.first * want > a){
            return false;
        }
        cost += s.first * want;
        count += want;
        if(count >= r) return true;
    }
    return false;
}

int solve(int start, ll r_, ll a){
    dijkstra(start);

    int l = -1, r = n;
    while(l + 1 < r){
        int mid = (l + r)/2;
        if(possible(mid,r_,a)) r = mid;
        else l = mid;
    }
    if(r == n) return -1;
    else return r;
}

int main(void){
    cin>>n>>m;
    rep(i,m){
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int w;
    cin>>w;
    shop.resize(w);
    rep(i,w){
        int c,k,p;
        cin>>c>>k>>p;
        shop[i] = {p,{c-1,k}};
    }
    sort(all(shop));

    int Q;
    cin>>Q;
    rep(_,Q){
        int start;
        ll r,a;
        cin>>start>>r>>a;
        start--;
        cout<<solve(start,r,a)<<endl;
    }

    return 0;
}
