#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;
typedef pair<ll,int> P;


ll dp[5001][5001];


int main(void){
    int n;
    cin>>n;
    vector<P> v(n);
    rep(i,n){
        cin>>v[i].first>>v[i].second;
        //sum + 
    }
    sort(all(v),[](const P &l, const P &r){ 
        return l.first + l.second < r.first + r.second;
    });
    rep(i,n+1)rep(j,n+1)dp[i][j] = (ll)1e9*1e9;
    cout<<dp[0][0]<<endl;

    rep(i,n){
        rep(j,n){
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            if(dp[i][j] <= v[i].first){
                dp[i+1][j+1] = min(dp[i][j+1],dp[i-1][j]+v[i].second);
            }
        }
    }
    // ll res = 0;
    // rep(i,n+1){
    //     res = max(dp[n-1][i],res);
    // }
    cout<<lower_bound(dp[n-1], dp[n-1]+n+1, (ll)INF*INF) - dp[n-1] - 1<<endl;
    return 0;
}
