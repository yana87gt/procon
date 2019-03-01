#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
typedef long long ll;

int main(void){
    int n;
    cin >> n;
    ll v[100010][3];
    rep(i,n) cin >> v[i][0] >> v[i][1] >> v[i][2];
    ll dp[100010][3] = {};
    rep(j,3) dp[0][j] = v[0][j];
    rep1(i,n-1) {
        rep(j,3) {
            dp[i][j] = max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + v[i][j];
        }
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;

    return 0;
}
