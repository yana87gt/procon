#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
const int INF = 1e9;

int main(void){
    int h,n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    vector<int> dp(h+1, INF);
    dp[h] = 0;
    rep(x,h) {
        int cur = h-x;
        rep(i,n){
            int to = max(cur-a[i], 0);
            dp[to] = min(dp[cur] + b[i], dp[to]);
        }
    }
    cout << dp[0] << endl;
    return 0;
}
