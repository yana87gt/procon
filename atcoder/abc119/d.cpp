#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
const ll INF = 1e11;

int main(void){
    int a,b,q;
    cin >> a >> b >> q;
    set<ll> setA = {-INF, +INF}, setB = {-INF, +INF};
    rep(i,a){
        ll s;
        cin >> s;
        setA.insert(s);
    }
    rep(i,b){
        ll t;
        cin >> t;
        setB.insert(t);
    }
    rep(i,q){
        ll x;
        cin >> x;
        ll a1 = *(--setA.lower_bound(x));
        ll a2 = *(setA.lower_bound(x));
        ll b1 = *(--setB.lower_bound(x));
        ll b2 = *(setB.lower_bound(x));
        cout << min({
            max(a2,b2)-x,
            x-min(a1,b1),
            (b2-x)*2 + (x-a1),
            (a2-x)*2 + (x-b1),
            (x-a1)*2 + (b2-x),
            (x-b1)*2 + (a2-x)
        }) << endl;
    }
    return 0;
}
