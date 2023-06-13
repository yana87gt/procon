///
/// for vscode snippet
/// prefix: lib-bfs
///

vector<int> shortest_path_bfs(vector<vector<int>> &graph, int start = 0, int inf = 1e7) {
    vector<int> dp(graph.size(), inf);
    queue<int> qu;
    qu.push(start);
    dp[start] = 0;
    while (!qu.empty()) {
        int cur = qu.front(); qu.pop();
        for (int to : graph[cur]) {
            if (dp[to] > dp[cur] + 1) {
                dp[to] = dp[cur] + 1;
                qu.push(to);
            }
        }
    }
    return dp;
}