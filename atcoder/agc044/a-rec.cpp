#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
const ll INF = 1e18;
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

ll n, a, b, c, d;
map<ll,ll> dp;

ll f(ll x) {
    if (dp.count(x)) return dp[x];
    if (x == 0) return 0;
    dp[x] = INF;
    if (x <= INF/d) {
        chmin(dp[x], x*d);
    }
    if (x % 2 == 0) {
        chmin(dp[x], a + f(x/2));
    } else {
        chmin(dp[x], d + a + f((x+1)/2));
        chmin(dp[x], d + a + f((x-1)/2));
    }

    if (x % 3 == 2) {
        chmin(dp[x], d + b + f((x+1)/3));
    } else {
        chmin(dp[x], d*(x%3) + b + f(x/3));
    }

    if (x % 5 <= 2) {
        chmin(dp[x], d*(x%5) + c + f(x/5));
    } else {
        chmin(dp[x], d*(5-x%5) + c + f(x/5 + 1));
    }

    return dp[x];
}

int main(void){
    int T;
    cin >> T;
    rep(t,T){
        cin >> n >> a >> b >> c >> d;
        cout << f(n) << endl;
        dp.clear();
    }
    return 0;
}
