#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

const ll INF = 1e18;
int main(void){
    int n, W;
    cin >> n >> W;
    int M = 100010;
    vector<ll> dp(M, INF);
    dp[0] = 0;
    rep(i,n){
        ll w,v;
        cin >> w >> v;
        for (int j = M; j >= 0; j--) {
            if (dp[j] == INF) continue;
            if (j+v > M) continue;
            dp[j+v] = min(dp[j+v], dp[j]+w);
        }
    }
    int res = 0;
    rep(j,M){
        if (dp[j] > W) continue;
        res = max(res, j);
    }
    cout << res << endl;
    return 0;
}
