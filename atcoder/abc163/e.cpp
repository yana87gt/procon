#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

using P = pair<ll, int>;

ll dp[2020][2020];

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<P> p(n);
    rep(i,n) {
        cin >> a[i];
        p[i] = {a[i], i};
    }
    sort(all(p),greater<P>());
    rep(i,n){
        int pos = p[i].second;
        // 左右合計iこ埋め済み
        rep(l,i+1){
            int r = i-l;
            // lこ埋め済み, rこ埋め済み
            if (l < n) {
                dp[l+1][r] = max(dp[l+1][r], dp[l][r] + a[pos] * abs(l-pos));
            }
            if (r < n) {
                dp[l][r+1] = max(dp[l][r+1], dp[l][r] + a[pos] * abs(n-1-r-pos));
            }
        }
    }
    ll res = 0;
    rep(l,n+1) {
        int r = n-l;
        res = max(dp[l][r],res);
    }
    cout << res << endl;
    return 0;
}
