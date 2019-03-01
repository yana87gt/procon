#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    using P = pair<int,int>;
    vector<P> vp(n);
    rep(i,n) {
        cin >> a[i] >> b[i];
        vp[i] = {a[i]+b[i], i};
    }
    sort(all(vp),greater<P>());
    ll res = 0;
    rep(i,n) {
        int id = vp[i].second;
        if (i%2 == 0) {
            res += a[id];
        } else {
            res -= b[id];
        }
    }
    cout << res << endl;
    return 0;
}
