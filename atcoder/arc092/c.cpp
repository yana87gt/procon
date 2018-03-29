#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

typedef pair<int,int> P;

int V;
vector<vector<int>> g;
vector<int> match;
vector<bool> used;

bool dfs(int v){
    used[v] = true;
    for(int u : g[v]){
        int w = match[u];
        if(w<0 || !used[w] && dfs(w)){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartite_matching() {
    int res = 0;
    match = vector<int>(V, -INF);
    rep(v,V){
        if(match[v] < 0){
            used = vector<bool>(V, false);
            if(dfs(v)){
                res++;
            }
        }
    }
    return res;
}

int main(void){
    int n;
    cin>>n;
    V = 2*n;
    g.resize(V);
    vector<P> red(n),blue(n);
    rep(i,n){
        int a,b;
        cin>>a>>b;
        red[i] = {a,b};
    }
    rep(i,n){
        int c,d;
        cin>>c>>d;
        blue[i] = {c,d};
    }
    rep(i,n)rep(j,n){
        if(red[i].first < blue[j].first && red[i].second < blue[j].second){
            int b = n+j;
            g[i].push_back(b);
            g[b].push_back(i);
        }
    }
    cout<<bipartite_matching()<<endl;
    return 0;
}
