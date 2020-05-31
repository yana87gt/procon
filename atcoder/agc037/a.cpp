#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int dp[200010][3];

int main(void){
    string s;
    cin >> s;
    int n = s.size();
    rep(i,n){
        rep1(d,2){
            if (i >= d) {
                if (s.substr(i-d, d) != s.substr(i, d)) {
                    dp[i+d][d] = max(dp[i+d][d], dp[i][d]+1);
                }
            }    
        }
        dp[i+1][1] = max(dp[i+1][1], dp[i][2]+1);
        dp[i+2][2] = max(dp[i+2][2], dp[i][1]+1);
    }
    cout << max(dp[n][1], dp[n][2]) << endl;
    return 0;
}
