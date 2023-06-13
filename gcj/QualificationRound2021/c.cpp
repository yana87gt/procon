#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(v) (v).begin(),(v).end()
#define INF int(1e9)

int calc_cost(int N, vector<int> a){
    int cost = 0;
    rep(i, N-1) {
        int pos = -1;
        int min_value = INF;
        for (int j = i; j < N; j++) {
            if (min_value > a[j]) {
                min_value = a[j];
                pos = j;
            }
        }
        cost += pos - i + 1;
        reverse(a.begin() + i, a.begin() + pos+1);
    }
    return cost;
}

void solve() {
    int N, C;
    cin >> N >> C;
    if (N > 7) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> a(N);
    iota(all(a), 1);
    do {
        int cost = calc_cost(N, a);
        if (cost == C) {
            rep(i,N) {
                cout << a[i] << (i < N - 1 ? " " : "\n");
            }
            return;
        }
    } while(next_permutation(all(a)));
    cout << "IMPOSSIBLE" << endl;
}

int main(void) {
    int T;
    cin >> T;
    rep(testcase, T){
        cout << "Case #" << testcase + 1 << ": ";
        solve();
    }
    return 0;
}
