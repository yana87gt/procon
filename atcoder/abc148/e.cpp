#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    ll n;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll res = 0;
    ll r = 2;
    rep(i,200){
        if (r*5LL > n) break;
        r *= 5LL;
        res += n/r;
    }
    cout << res << endl;
    return 0;
}
