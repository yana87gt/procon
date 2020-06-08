#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
const int INF = 2e9;

int main(void){
    int N, L;
    cin >> N >> L;
    vector<bool> h(L+10);
    rep(i,N) {
        int x;
        cin >> x;
        h[x] = true;
    }
    int T1, T2, T3;
    cin >> T1 >> T2 >> T3;
    vector<int> dp(L+20, INF);
    dp[0] = 0;
    rep(i,L){
        if (h[i]) dp[i] += T3;
        dp[i+1] = min(dp[i+1], dp[i] + T1);
        dp[i+2] = min(dp[i+2], dp[i] + T1 + T2);
        dp[i+4] = min(dp[i+4], dp[i] + T1 + T2*3);
        if (i+2 > L) {
            dp[L] = min(dp[L], dp[i] + T1/2 + T2/2);
        }
        if (i+4 > L) {
            dp[L] = min(dp[L], dp[i] + T1/2 + T2/2 + T2*(L-i-1));
        }
    }
    cout << dp[L] << endl;
    return 0;
}
