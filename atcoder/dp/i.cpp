#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

double dp[3010][3010];

int main(void){
    int n;
    cin >> n;
    dp[0][0] = 1.0;
    rep(i,n){
        double p;
        cin >> p;
        rep(j,i+1){
            dp[j+1][i-j] += dp[j][i-j]*p;
            dp[j][i-j+1] += dp[j][i-j]*(1.0-p);
        }
    }
    double res = 0;
    rep(i,n+1){
        if(i >= n-i){
            res += dp[i][n-i];
        }
    }
    printf("%.20f\n", res);
    return 0;
}
