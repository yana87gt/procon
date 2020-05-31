#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

ll gcd(ll x, ll y){return y == 0 ? x : gcd(y,x%y);}

vector<ll> a;
int n;

ll seg_gcd(int l, int r){
    ll g;
    if (l > 0) g = a[0];
    else g = a[r];
    rep(i,l) {
        g = gcd(g, a[i]);
    }
    for (int i = r; i < n; i++) {
        g = gcd(g, a[i]);
    }
    return g;
}

ll solve(int l, int r) {
    ll res = 0;
    for (int x = l; x < r; x++) {
        res = max(res,seg_gcd(x, x+1));
    }
    return res;
}


int main(void){
    cin >> n;
    a.resize(n);
    rep(i,n) cin >> a[i];
    int l = 0, r = n;
    while (l+1 < r) {
        if (r-l < 10) {
            cout << solve(l, r) << endl;
            return 0;
        }
        int mid = (l+r)/2;
        ll res1 = seg_gcd(l, mid);
        ll res2 = seg_gcd(mid, r);
        if (res1 > res2) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << seg_gcd(l, r) << endl;
    return 0;
}
