#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    vector<ll> dp(n);
    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout << dp[n-1] << endl;
    return 0;
}
