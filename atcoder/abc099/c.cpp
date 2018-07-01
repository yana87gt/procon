#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    vector<int> v = {1};
    for(int r = 6; r <= n; r *= 6) v.push_back(r);
    for(int r = 9; r <= n; r *= 9) v.push_back(r);
    vector<int> dp(n+1,n);
    dp[0] = 0;
    rep(i,n)for(int d : v)if(i+d <= n){
        if( dp[i+d] > dp[i] + 1 ){
            dp[i+d] = dp[i] + 1;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
