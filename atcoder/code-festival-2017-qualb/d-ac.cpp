#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    string s;
    cin>>N>>s;
    s = "0"+s+"0";
    vector<int> dp(N+2);
    for(int i=1;i<=N;++i){
        dp[i+1] = max(dp[i+1],dp[i]);
        if(s.substr(i-1,3)!="101") continue;
        // 貰うDP
        for(int l=i-1; s[l]!='0'; l--){
            dp[i+1] = max(dp[i+1],dp[l-1]+(i-l));
        }
        // 配るDP
        for(int r=i+1; s[r]!='0'; r++){
            dp[r] = max(dp[r],dp[i-2]+(r-i));
        }
    }
    cout<<dp[N+1]<<endl;
}
