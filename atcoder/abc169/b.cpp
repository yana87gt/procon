#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
const ll INF = 1e18;

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if (count(all(a), 0)) {
        cout << 0 << endl;
        return 0;
    }
    ll res = 1;
    rep(i,n) {
        if (res <= INF / a[i]) {
            res *= a[i];
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ((res <= INF) ? res : -1LL) << endl;
    return 0;
}
