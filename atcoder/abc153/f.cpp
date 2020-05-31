#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    ll n, d, a;
    cin >> n >> d >> a;
    using P = pair<ll, ll>;
    vector<P> v(n);
    rep(i,n){
        ll x, h;
        cin >> x >> h;
        h = (h-1)/a + 1;
        v[i] = {x,h};
    }
    sort(all(v));
    map<ll, ll> del;
    ll sum = 0, damage = 0;
    rep(i,n){
        ll x = v[i].first;
        ll h = v[i].second;
        while (!del.empty()) {
            ll r = del.begin()->first;
            if (x <= r) break;
            damage -= del[r];
            del.erase(del.begin());
        }
        assert(damage >= 0);
        h = max(0LL, h - damage);
        sum += h;
        damage += h;
        del[x+d*2] += h;
    }
    cout << sum << endl;
    return 0;
}
