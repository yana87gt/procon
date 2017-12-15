#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;



#define M 1000000007

map<int,int> h;

ll mul(ll a,ll b){ return (a*b)%M;}
ll add(ll a,ll b){ return (a+b)%M;}


ll power(ll n, ll r)
{
    if(r==1)return n;
    if(r%2==0)return power(mul(n,n),r/2);
    else return mul(power(mul(n,n),r/2),n);
}

const int MAX = 200010;
const int MAX_LOG = 100;

int n, Q;
vector<int> edge[MAX];

int parent[MAX_LOG][MAX];
int depth[MAX];

void dfs(int curr, int prev, int d) {
  parent[0][curr] = prev;
  depth[curr] = d;
  
  rep(i, edge[curr].size()) {
    if(edge[curr][i] != prev) {
      dfs(edge[curr][i], curr, d + 1);
    }
  }
}

void init(int V) {
  dfs(0, -1, 0);
  
  rep(k, MAX_LOG - 1) {
    rep(v, V) {
      if(parent[k][v] < 0) parent[k + 1][v] = -1;
      else parent[k + 1][v] = parent[k][parent[k][v]];
    }
  }
}

int lca(int u, int v) {
  if(depth[u] > depth[v]) swap(u, v);

  rep(k, MAX_LOG) {
    if((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if(u == v) return u;
  
  for(int k = MAX_LOG - 1; k >= 0; k--) {
    if(parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}


// void dfs(int v,int depth){
//     h[depth]++;
//     if(ch[v].size() == 0){
//         return;
//     }
//     for(auto child : ch[v]){
//         dfs(child,depth+1);
//     }
// }

int main(void){
    cin>>n;
    rep1(i,n){
        int p;
        cin>>p;
        edge[i].push_back(p);
        edge[p].push_back(i);
    }

    dfs(0,0);
    ll res=0;
    for(auto itr : h){
        int c = itr.second;
        res = add(res,mul(power(2,n+1-c),c));
    }
    cout<<res<<endl;

    return 0;
}
