// -------- START : snippet -------- //

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF int(1e9)

int main(void) {
    int T;
    cin >> T;
    rep(test_case, T){
        cout << "Case #" << test_case + 1 << ": ";
        int N;
        cin >> N;
        vector<int> a(N);
        rep(i, N) cin >> a[i];
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
        cout << cost << endl;
    }
    return 0;
}
