#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

vector<vector<int>> g;

int get_cutsize(int par, int v, int rem) {
    int sum = (rem < 0 ? 1 : 0);
    for (int child : g[v]) {
        if (child == par) continue;
        sum += get_cutsize(v, child, rem-1);
    }
    return sum;
}

int main(void){
    int n, k;
    cin >> n >> k;
    g.resize(n);
    vector<int> a(n),b(n);
    rep(i,n-1){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    int res = n;
    if (k%2 == 0) {
        rep(v,n) {
            res = min(res, get_cutsize(-1, v, k/2));
        }
    } else {
        rep(i,n-1) {
            res = min(res, get_cutsize(a[i], b[i], k/2) + get_cutsize(b[i], a[i], k/2));
        }
    }
    cout << res << endl;

    return 0;
}
