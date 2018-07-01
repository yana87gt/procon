#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e9

int gcd(int a,int b){return b==0 ? a : gcd(b,a%b);}

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

int main(void){
    int m,n;
    while(cin>>m>>n, n|m){
        vector<int> b(m),r(n);
        rep(i,m) cin>>b[i];
        rep(i,n) cin>>r[i];

        vector<vector<int>> g(m+n);
        rep(i,m)rep(j,n){
            if(gcd(b[i],r[j]) > 1){
                g[i].push_back(m+j);
                g[m+j].push_back(i);
            }
        }
        cout<<bipartite_matching(g)<<endl;
    }
    return 0;
}
