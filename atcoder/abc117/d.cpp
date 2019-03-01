#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
#define bit(k) (1LL<<(k))

int n;
ll cnt[60] = {};

ll calc(ll x) {
    ll sum = 0;
    rep(i,60){
        if (x & bit(i)) {
            sum += bit(i) * max(cnt[i], n-cnt[i]);
        } else {
            sum += bit(i) * cnt[i];
        }
    }
    return sum;
}

int main(void){
    ll K;
    cin >> n >> K;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        rep(j,60) if(bit(j) & a[i]) {
            cnt[j]++;
        }
    }

    ll res = max(calc(0),calc(K));
    rep(i,60) {
        if (bit(i) & K) {
            res = max(res, calc((K^bit(i))|(bit(i)-1)));
        }
    }
    cout << res << endl;
    return 0;
}
