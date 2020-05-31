///
/// for vscode snippet
/// prefix: lib-bipartite_matching
///

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
