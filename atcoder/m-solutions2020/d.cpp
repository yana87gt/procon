#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void) {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    a.push_back(0);
    ll m = 1000;
    ll s = 0;
    rep(i,n){
        if (a[i] < a[i+1]) {
            s += m / a[i];
            m -= (m / a[i])*a[i];
        }
        if (a[i] > a[i+1]) {
            m += s*a[i];
            s = 0;
        }
    }
    cout << m << endl;
    return 0;
}
