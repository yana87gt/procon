#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    vector<int> a(1<<n);
    rep(i,1<<n) cin>>a[i];
    using P = pair<int,int>;
    vector<set<P>> dp(1<<n);
    rep(i,1<<n){
        dp[i].insert({a[i],i});
        while((int)dp[i].size() > 2){
            dp[i].erase(dp[i].begin());
        }
        for(P p : dp[i]){
            rep(k,n){
                dp[(1<<k)|i].insert(p);
            }
        }
    }
    ll mx = 0;
    rep1(i,(1<<n)-1){
        ll res = 0;
        for(P p : dp[i]){
            res += p.first;
        }
        mx = max(res,mx);
        cout<<mx<<endl;
    }
    return 0;
}
