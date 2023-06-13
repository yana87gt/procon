#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void) {
    ll N, C;
    cin >> N >> C;
    map<ll, ll> imos;
    rep(i,N) {
        ll a,b,c;
        cin >> a >> b >> c;
        imos[a] += c;
        imos[b+1] -= c;
    }
    ll acm = 0;
    for (auto &itr : imos) {
        itr.second += acm;
        acm = itr.second;
    }
    ll sum = 0;
    ll l = imos.begin()->first;
    for (auto &itr : imos) {
        ll r = itr.first;
        if (l == r) continue;
        ll cost = imos[l];
        if (C < cost) {
            sum += C * (r - l);
        } else {
            sum += cost * (r - l);
        }
        l = r;
    }
    cout << sum << endl;

    return 0;
}
