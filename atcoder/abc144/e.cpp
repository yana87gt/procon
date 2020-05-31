#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> f[i];
    sort(all(a));
    sort(all(f), greater<ll>());
    ll ng = -1, ok = 1e12;
    while (ng + 1 < ok) {
        ll t = (ng + ok)/2;
        auto check = [&]() {
            ll sum = 0;
            rep(i,n) {
                ll x = ceil(a[i]-(double)t/f[i]);
                if (x > 0) sum += x;
            }
            return sum <= k; 
        };
        if (check()) {
            ok = t;
        } else {
            ng = t;
        }
    }
    cout << ok << endl;

    return 0;
}
