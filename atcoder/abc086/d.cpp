#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int dp[2][1001][1001];
//dp[0]:white, dp[1]:black

int main(void){
    int n,k;
    cin>>n>>k;
    rep(i,n){
        int x,y;
        string c;
        cin>>x>>y>>c;
        bool isB = (c=="B")^((x/k + y/k)&1);
        dp[isB][y%k + 1][x%k + 1]++;
    }

    rep1(y,k)rep1(x,k)rep(i,2){
        dp[i][y][x] += dp[i][y-1][x] + dp[i][y][x-1] - dp[i][y-1][x-1];
    }

    int res = 0;
    rep1(y,k)rep1(x,k)rep(i,2){
        int cnt1 = dp[i][k][k] - dp[i][y][k] - dp[i][k][x] + 2*dp[i][y][x];
        int cnt2 = dp[!i][y][k] + dp[!i][k][x] - 2*dp[!i][y][x];
        res = max(res, cnt1+cnt2);
    }
    cout<<res<<endl;
    return 0;
}
