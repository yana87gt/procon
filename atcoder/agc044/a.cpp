#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
const ll INF = 1e18;

int main(void){
    int T;
    cin >> T;
    rep(t,T){
        ll n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        map<ll,ll> dp;
        using P = pair<ll, ll>;
        priority_queue<P,vector<P>,greater<P>> qu;
        auto update = [&](ll nx, ll nc) {
            if (dp.count(nx) == 0 || dp[nx] > nc) {
                qu.push({dp[nx] = nc, nx});
            }
        };
        qu.push({dp[n] = 0,n});
        while(qu.size()) {
            P top = qu.top(); qu.pop();
            ll cost = top.first;
            ll x = top.second;
            if (x == 0) break;
            if (dp[x] < cost) continue;

            if (x <= (INF - cost)/d) {
                update(0, cost + x*d);
            }

            if (x % 2 == 0) {
                update(x/2, cost + a);
            } else {
                update(x/2, cost + a + d);
                update(x/2 + 1, cost + a + d);
            }

            if (x % 3 <= 1) {
                update(x/3, cost + b + d*(x%3));
            } else {
                update(x/3 + 1, cost + b + d);
            }

            if (x % 5 <= 2) {
                update(x/5, cost + c + d*(x%5));
            } else {
                update(x/5 + 1, cost + c + d*(5-x%5));
            }
        }
        cout << dp[0] << endl;
    }
    return 0;
}
