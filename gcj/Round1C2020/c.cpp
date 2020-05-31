#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

void solve(){
    int n, d;
    cin >> n >> d;
    vector<ll> a(n);
    set<ll> divs;
    rep(i,n) {
        cin >> a[i];
        a[i] *= d;
        rep1(p,d) {
            if (a[i] % p == 0) {
                divs.insert(p);
                divs.insert(a[i]/p);
            }
        }
    }

    ll res = d-1;
    sort(all(a));
    for (ll x : divs) {
        vector<ll> b;
        rep(i,n) if (a[i] % x == 0) b.push_back(a[i]);
        rep(i,n) if (a[i] % x != 0) b.push_back(a[i]);
        ll cut = 0, piece = 0;
        for (ll y : b) {
            if (piece + y/x > d) {
                cut += d - piece;
            } else {
                cut += y/x;
                if (y % x == 0) cut--;
            }
            piece += y/x;
            if (piece >= d) {
                res = min(res, cut);
                break;
            }
        }
    }
    cout << res << endl;
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        solve();
    }
    return 0;
}
