#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    ll n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a),greater<ll>());
    int res = p;
    ll acm = a[p-1];
    ll k = 1;
    for (int i = p; i < n; i++){
        if (a[i]+m < a[p-1]) break;
        ll cap = (a[i]+m)*k - acm + (n-p-k)*m;
        ll rem = (v-p)*m;
        if (cap >= rem) res++;
        k++;
        acm += a[i];
    }
    cout << res << endl;
    return 0;
}
