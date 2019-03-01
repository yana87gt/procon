#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

vector<int> par[100010];
vector<int> ch[100010];
int depth[100010];
int n, m;

int dfs(int v){
    if (par[v].size() == 0) {
        depth[v] = 0;
        return 0;
    }
    if (depth[v]) return depth[v];
    for (int p : par[v]) {
        depth[v] = max(dfs(p)+1, depth[v]);
    }
    return depth[v];
}

int main(void){
    cin >> n >> m;
    rep(i,n-1+m){
        int a,b;
        cin >> a >> b;
        a--,b--;
        ch[a].push_back(b);
        par[b].push_back(a);
    }
    rep(i,n) dfs(i);
    rep(i,n){
        int true_par = -1;
        int max_depth = 0; 
        for(int p : par[i]){
            if (max_depth <= depth[p]) {
                max_depth =  depth[p];
                true_par = p;
            }
        }
        cout << true_par+1 << endl;
    }

    return 0;
}
