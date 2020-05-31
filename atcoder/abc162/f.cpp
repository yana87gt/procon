#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define INF (ll)1e16

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int MAX_JUMP = (n % 2 == 0) ? 2 : 3;
    vector<ll> dp[MAX_JUMP];
    rep(i,MAX_JUMP) dp[i] = vector<ll>(n, -INF);
    rep(i,MAX_JUMP) dp[i][i] = a[i];
    rep(i,n){
        rep(k,MAX_JUMP){
            if (i < k) continue;
            rep(j,MAX_JUMP){
                if (k+j <= MAX_JUMP-1 && i+j+2 < n){
                    dp[k+j][i+j+2] = max(dp[k+j][i+j+2], dp[k][i] + a[i+j+2]);
                }
            }
        }
    }
    if (n % 2 == 0){
        cout << max({dp[1][n-1], dp[0][n-2]}) << endl;
    } else {
        cout << max({dp[2][n-1], dp[1][n-2], dp[0][n-3]}) << endl;
    }

    return 0;
}
