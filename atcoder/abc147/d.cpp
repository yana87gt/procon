#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
#define bit(k) (1LL<<(k))

int main(void){
    ll n;
    cin >> n;
    int m = 60;
    vector<ll> cnt(m);
    rep(i,n){
        ll a;
        cin >> a;
        rep(j,m){
            if (bit(j) & a) cnt[j]++;
        }
    }
    ll res = 0;
    ll MOD = 1e9+7;
    rep(i,m){
        res += ((cnt[i]*(n-cnt[i]))%MOD * (bit(i)%MOD))%MOD;
    }
    cout << res%MOD << endl;
    return 0;
}
