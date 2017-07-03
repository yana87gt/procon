typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;

// res: bridges
// v: current node
// from: parent node
int dfs(VVI& g, vector<PI>& res, int v, int& count, int from, VI& low, VI& pre) {
    pre[v] = count++;
    low[v] = pre[v];
    for (int to:g[v]) {
        if (pre[to] == -1) {
            // destination has not been visited
            // visit destination and update low[v]
            low[v] = min(low[v], dfs(g, res, to, count, v, low, pre));
            if (low[to] == pre[to]) {
                // edge is not contained in a closed path -> bridge
                res.push_back(make_pair(v, to));
            }
        } else {
            if (from == to) {
                // ignore a path to parent
                continue;
            }
            low[v] = min(low[v], low[to]);
        }
    }
    return low[v];
}

// Calculate bridges in a undirected graph.
// Assume graph is connected and has no parallel edges or self-loops.
// g: adjacency list
// V: number of nodes
vector<PI> bridges(VVI& g, int V) {
    vector<PI> res;
    if (V > 0) {
        // assume at least the first vertex exists
        VI low(V, -1);  // lowest reacheable index
        VI pre(V, -1);  // pre-order index
        int count = 0;  // pre-order index counter
        dfs(g, res, 0, count, -1, low, pre);  // start dfs from vertex 0
    }
    return res;
}