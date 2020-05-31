#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define bit(k) (1LL<<(k))
const int INF = 1e9;

int main(void){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n);
    int res = INF;
    rep(i,n){
        a[i].resize(m);
        cin >> c[i];
        rep(j,m) cin >> a[i][j];
    }
    rep(mask, 1<<n) {
        int cost = 0;
        vector<int> b(m);
        rep(i,n){
            if (bit(i) & mask) {
                cost += c[i];
                rep(j,m){
                    b[j] += a[i][j];
                }
            }
        }
        bool ok = true;
        rep(j,m) {
            if (b[j] < x) ok = false;
        }
        if (ok) {
            res = min(res, cost);
        }
    }
    cout << ((res == INF) ? -1 : res) << endl;
    return 0;
}
