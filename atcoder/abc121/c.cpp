#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    int n,m;
    cin >> n >> m;
    using P = pair<ll,ll>;
    vector<P> vp(n);
    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        vp[i] = {a,b};
    }
    sort(all(vp));
    ll res = 0;
    rep(i,n){
        ll a = vp[i].first, b = vp[i].second;
        if(m-b > 0) {
            res += a*b;
            m -= b;
        } else {
            res += a*m;
            break;
        }
    }
    cout << res << endl;
    return 0;
}
