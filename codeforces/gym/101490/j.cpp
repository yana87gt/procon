#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

const int INF = 1e9;

bool dfs(int v,vector<vector<int>> &g,
    vector<int> &match,vector<bool> &used){

    used[v] = true;
    for(int u : g[v]){
        int w = match[u];
        if(w<0 || (!used[w] && dfs(w,g,match,used))){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}
 
int bipartite_matching(vector<vector<int>> &g){
    int res = 0;
    int V = g.size();
    vector<int> match(V, -INF);
    rep(v,V){
        if(match[v] < 0){
            vector<bool> used(V, false);
            if(dfs(v,g,match,used)){
                res++;
            }
        }
    }
    return res;
}


using P = pair<int,int>;

int dist(P a, P b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int d[100][100] = {};
int n;
bool check(int k){
    vector<vector<int>> g(n*2);
    rep(i,n)rep(j,n){
        if(d[i][j] <= k){
            g[i].push_back(n+j);
            g[n+j].push_back(i);
        }
    }
    int match = bipartite_matching(g);
    return match == n;
}

int main(void){
    cin>>n;
    vector<P> a(n),b(n);
    rep(i,n){
        int x,y;
        cin>>x>>y;
        a[i] = {x,y};
    }
    rep(i,n){
        int x,y;
        cin>>x>>y;
        b[i] = {x,y};
    }

    int l = -1, r = 0;
    rep(i,n) rep(j,n){
        d[i][j] = dist(a[i],b[j]);
        r = max(r, d[i][j]);
    }
    while(l+1 < r){
        int m = (l+r)/2;
        if(check(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout<<r<<endl;

    return 0;
}

