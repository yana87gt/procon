#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll X, Y;
map<ll,ll> dp;
ll f(ll y) {
    if (dp.count(y)) return dp[y];
    if (y <= X) return X-y;
    if (y % 2 == 0) dp[y] = min(y-X, f(y/2) + 1);
    else dp[y] = min({y-X, f((y-1)/2) + 2, f((y+1)/2) + 2});
    return dp[y];
}
int main(void) {
    cin >> X >> Y;
    cout << f(Y) << endl;
    return 0;
}
