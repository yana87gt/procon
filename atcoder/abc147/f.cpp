#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

ll solve(){
    ll n,x,d;
    cin >> n >> x >> d;
    if (d == 0) {
        return x == 0 ? 1 : n+1;
    }
    if (d < 0) {
        x = -x;
        d = -d;
    }
    map<ll, vector<pair<ll,ll>>> seg;
    for (ll k = 0; k <= n; k++) {
        seg[k*x % d].push_back({
            k*x + d*(k-1)*k/2,
            k*x + d*(2*n-k-1)*k/2
        });
    }
    ll res = 0;
    for (auto itr : seg) {
        vector<pair<ll,ll>> &v = itr.second;
        sort(all(v));
        ll l = v[0].first;
        ll r = v[0].second;
        rep1(i, (int)v.size()-1) {
            if (r < v[i].first) {
                res += (r-l)/d+1;
                l = v[i].first;
                r = v[i].second;
            } else {
                r = max(r, v[i].second);
            }
        }
        res += (r-l)/d+1;
    }
    return res;
}

int main(void){
    cout << solve() << endl;
    return 0;
}
