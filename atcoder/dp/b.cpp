#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

typedef long long ll;

int main(void){
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    vector<ll> dp(n, 1e18);
    dp[0] = 0;
    rep(i,n){
        rep1(j,k){
            if (i<j) break;
            dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}
