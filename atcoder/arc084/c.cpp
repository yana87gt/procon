#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define ub(s,x) upper_bound(all(s),x)-s.begin()
#define INF 1e9
typedef long long ll;

int main(void){
    int N;
    cin>>N;
    vector<ll> a(N),b(N),c(N),dp(N+1);
    rep(i,N)cin>>a[i];
    rep(i,N)cin>>b[i];
    rep(i,N)cin>>c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));

    ll res = 0;
    rep(i,N){
        int pos = ub(c,b[N-i-1]);
        dp[N-i-1] = dp[N-i] + N-pos;
    }
    rep(i,N){
        int pos = ub(b,a[i]);
        res += dp[pos];
    }
    cout<<res<<endl;
    return 0;
}
