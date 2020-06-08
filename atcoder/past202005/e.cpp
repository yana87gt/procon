#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n);
    vector<int> c(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i,n) cin >> c[i];
    rep(loop, q){
        int q_type;
        cin >> q_type;
        if (q_type == 1) {
            int x;
            cin >> x;
            x--;
            cout << c[x] << endl;
            for(int to : g[x]) {
                c[to] = c[x];
            }
        } else {
            int x,y;
            cin >> x >> y;
            x--;
            cout << c[x] << endl;
            c[x] = y;
        }
    }
    return 0;
}
