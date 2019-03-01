#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define bit(k) (1<<(k))

int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> x(m),y(m);
    rep(i,m){
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }
    vector<ll> dp(1<<n);
    dp[0] = 1;
    rep(mask,1<<n){
        bool ng = false;
        rep(i,m){
            if(!(mask & bit(x[i])) && (mask & bit(y[i]))){
                ng = true;
            }
        }
        if(ng) continue;
        rep(to,n){
            if(bit(to) & mask) continue;
            dp[bit(to) | mask] += dp[mask];
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}
