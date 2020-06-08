#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int N,M,Q;
    cin >> N >> M >> Q;
    vector<vector<int>> solved(N);
    vector<int> point(M, N);
    rep(i,Q) {
        int q_type;
        cin >> q_type;
        if (q_type == 1) {
            int n;
            cin >> n;
            n--;
            int sum = 0;
            for (int t : solved[n]) {
                sum += point[t];
            }
            cout << sum << endl;
        } else {
            int n,m;
            cin >> n >> m;
            n--, m--;
            solved[n].push_back(m);
            point[m]--;
        }
    }
    return 0;
}
