#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define INF 2e9
#define updmin(dp,x) (dp = min(dp,x))

int main(void){
    int n,m;
    while(cin>>n>>m, n|m){
        vector<int> c(m);
        rep(i,m) cin>>c[i];
        vector<int> x(n);
        rep(i,n) cin>>x[i];
        vector<vector<int>> dp(n+1,vector<int>(256,INF));
        dp[0][128] = 0;
        rep(i,n)rep(y,256)rep(k,m){
            int ny = max(0,min(255,y+c[k]));
            updmin(dp[i+1][ny], dp[i][y]+(int)pow(x[i]-ny,2));
        }
        cout<<*min_element(all(dp[n]))<<endl;
    }
    return 0;
}
