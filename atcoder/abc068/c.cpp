#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

vector<int> g[200010];
int d[200010];

void dfs(int v,int depth){
    if(depth>2 || d[v]>0)return;
    d[v] = depth;
    for(int u : g[v]){
        dfs(u,depth+1);
    }
}

int main(void){
    int n,m;
    cin>>n>>m;

    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,0);
    cout<<(d[n-1]==2 ? "POSSIBLE" : "IMPOSSIBLE")<<endl;
    return 0;
}
