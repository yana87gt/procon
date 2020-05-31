#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

vector<vector<int>> g;

using P = pair<int,int>; // <端点からの頂点の個数, 端点>
P dfs(int pre, int cur){
    P ans = {0, cur};
    for(int to : g[cur]) if(to != pre) {
        ans = max(ans, dfs(cur, to));
    }
    ans.first++;
    return ans;
}

int main(void){
    int n;
    cin >> n;
    g.resize(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int diameter = dfs(-1, dfs(-1, 0).second).first;
    cout << ((diameter % 3 != 2) ? "First" : "Second") << endl;

    return 0;
}
