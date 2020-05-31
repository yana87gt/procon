#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

vector<int> g[100010];
int d[100010];
int res = 0;

// for d[]
void dfs(int pre, int cur, int depth) {
    d[cur] = depth;
    for(int to : g[cur]){
        if (to == pre) continue;
        dfs(cur, to, depth + 1);
    }
}

void chase(int pre, int cur, int turn) {
    if (turn >= d[cur] && (int)g[cur].size() > 1) {
        res = max(res, turn);
    }
    for(int to : g[cur]){
        if (to == pre) continue;
        chase(cur, to, turn + 1);
    }
}

int main(void){
    int n, u, v;
    cin >> n >> u >> v;
    u--,v--;
    rep(i,n-1){
        int x,y;
        cin >> x >> y;
        x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(-1,u,0);
    chase(-1,v,0);
    cout << res << endl;
    return 0;
}
