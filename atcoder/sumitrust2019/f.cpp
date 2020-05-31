#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll t[2], a[2], b[2];
    cin >> t[0] >> t[1];
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    ll am = t[0]*a[0];
    ll bm = t[0]*b[0];
    ll ah = t[0]*a[0] + t[1]*a[1];
    ll bh = t[0]*b[0] + t[1]*b[1];
    if (ah == bh) {
        cout << "infinity" << endl;
        return 0;
    }
    if ((am-bm > 0) ^ (ah-bh > 0)) {
        ll dm = abs(am-bm);
        ll dh = abs(ah-bh);
        ll res = (dm/dh)*2+1;
        if (dm % dh == 0) res--;
        cout << res << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
