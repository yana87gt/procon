#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin>>s;
    vector<int> dp(1<<26,1e9);
    dp[0] = 0;
    int bit = 0;
    rep(i,s.size()){
        bit ^= (1<<(s[i]-'a'));
        rep(j,26) dp[bit] = min(dp[bit], dp[bit^(1<<j)]+1);
    }
    cout<<max(1,dp[bit])<<endl;
}
