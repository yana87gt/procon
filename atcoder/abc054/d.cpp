#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

int main(void){
    int n,ma,mb;
    cin>>n>>ma>>mb;
    vector<int> a(n),b(n),c(n);
    rep(i,n) cin>>a[i]>>b[i]>>c[i];
    int dp[401][401];
    rep(i,401)rep(j,401)dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=400;i>=0;i++){
        
    }
    return 0;
}
