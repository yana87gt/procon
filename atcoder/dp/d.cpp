#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    int n, W;
    cin >> n >> W;
    vector<ll> dp(W+1, -1);
    dp[0] = 0;
    rep(i,n){
        ll w,v;
        cin >> w >> v;
        for (int j = W; j >= 0; j--) {
            if (dp[j] == -1) continue;
            if (j+w > W) continue;
            dp[j+w] = max(dp[j+w], dp[j]+v);
        }
    }
    cout << *max_element(all(dp)) << endl;
    return 0;
}
