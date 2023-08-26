#include <bits/stdc++.h>
using namespace std;

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define all(v) (v).begin(), (v).end()

int d[10][10];

int main(void) {
    int N, M;
    cin >> N >> M;
    rep(i, N) rep(j, N) d[i][j] = -1;
    rep(i, M) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--, v--;
        d[u][v] = d[v][u] = cost;
    }
    vector<int> a(N);
    rep(i, N) a[i] = i;
    int max_dist = 0;
    do {
        int dist = 0;
        rep(i, N - 1) {
            if (d[a[i]][a[i + 1]] >= 0) {
                dist += d[a[i]][a[i + 1]];
            } else {
                break;
            }
        }
        max_dist = max(max_dist, dist);
    } while (next_permutation(all(a)));
    cout << max_dist << endl;
    return 0;
}
