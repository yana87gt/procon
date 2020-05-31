#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 2019;

int main(void){
    ll l,r;
    cin >> l >> r;
    if (r-l > MOD) {
        cout << 0 << endl;
    } else {
        ll res = MOD;
        for (ll i = l; i < r; i++) {
            for (ll j = l+1; j <= r; j++) {
                res = min(res, (i*j)%MOD);
            }
        }
        cout << res << endl;
    }
    return 0;
}
