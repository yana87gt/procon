///
/// for vscode snippet
/// prefix: lib-centroid
///

#define MAXN 2010

// 木のクラスを作って、中心とかいろいろ一緒にライブラリ化しような

vector<int> g[MAXN];
bool centroid[MAXN]; // 重心になったことがある
int subSize[MAXN];   // ある頂点をrootとしたときの部分木のサイズ

int getSubSize(int v, int p) {
    int& sum = subSize[v];
    sum = 1;
    for(int ch : g[v]){
        if (ch == p || centroid[ch]) continue;
        sum += getSubSize(ch, v);
    }
    return sum;
}

vector<int> Centroid(const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> centroid;
    vector<int> sz(n);
    function<void (int, int)> dfs = [&](int u, int prev) {
        sz[u] = 1;
        bool is_centroid = true;
        for (auto v : g[u]) if (v != prev) {
            dfs(v, u);
            sz[u] += sz[v];
            if (sz[v] > n / 2) is_centroid = false;
        }
        if (n - sz[u] > n / 2) is_centroid = false;
        if (is_centroid) centroid.push_back(u);
    };
    dfs(0, -1);
    return centroid;
}

// t: 分解された木のサイズ
// secondが重心
pair<int,int> getCentroid(int v, int p, int t) {
    pair<int,int> ret(INF, -1);
    // m: 頂点vを根にした時の部分木の中で最大のサイズ
    int sum = 1, m = 0;
    for(int ch : g[v]){
        if (ch == p || centroid[ch]) continue;
        m = max(m, subSize[ch]);
        sum += subSize[ch];
        ret = min(ret, getCentroid(ch, v, t));
    }
    m = max(m, t-sum);
    ret = min(ret, pair<int,int>(m, v));
    return ret;
}

// pから見てvへの辺を除去
void eraseEdge(int v,int p){
    rep(i,g[p].size())if(g[p][i]==v){
        g[p].erase(g[p].begin()+i);
    }
}

void solve(){
    getSubSize(v,-1);
    int c = getCentroid(v,-1,subSize[v]).second;
    centroid[c] = true;
}
