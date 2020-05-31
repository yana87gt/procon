#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    vector<vector<int>> g(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = 0;
    rep(i,n){
        bool is_good = true;
        for (int nxt : g[i]) {
            if (h[i] <= h[nxt]) {
                is_good = false;
            }
        }
        if (is_good) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
