#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

ll mul(ll a, ll b, ll mod) {
    return (a*b)%mod;
}
ll mpow(ll a, ll r, ll mod) {
    if(r == 0) return 1;
    return mul(mpow(mul(a,a,mod), (r/2), mod), (r&1 ? a : 1), mod);
}

void f(ll x, ll &cnt) {
    if (x == 0) return;
    cnt++;
    f(x % __builtin_popcountll(x), cnt);
}

int main(void) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll M = count(all(s), '1');
    ll fx1 = 0, fx2 = 0;
    reverse(all(s));
    rep(i,n) {
        if (s[i] == '1') {
            if (M == 1) {
                fx1 = 0;
            } else {
                fx1 += mpow(2, i, M-1);
                fx2 += mpow(2, i, M+1);
            }
        }
    }
    vector<ll> res;
    rep(i,n){
        ll fx;
        if (s[i] == '1' && M == 1) {
            res.push_back(0);
            continue;
        } else if (s[i] == '1') {
            fx = (fx1 - mpow(2, i, M-1) + (M-1) ) % (M-1);
        } else {
            fx = (fx2 + mpow(2, i, M+1) + (M+1) ) % (M+1);
        }
        ll cnt = 1;
        f(fx, cnt);
        res.push_back(cnt);
    }
    reverse(all(res));
    rep(i,n){
        cout << res[i] << endl;
    }
    
    return 0;
}