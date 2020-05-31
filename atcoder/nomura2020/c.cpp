#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n+1), p(n+1), s(n+1);
    rep(i,n+1) {
        cin >> a[i];
    }
    if (n == 0) {
        cout << ((a[0] == 1) ? 1 : -1) << endl;
        return 0;
    }
    if (a[0] == 1) {
        cout << -1 << endl;
        return 0;
    }
    s[n] = a[n];
    p[n] = 0;
    for (int d = n-1; d >= 0; d--) {
        s[d] = s[d+1] + a[d];
        p[d] = s[d] - a[d];
        if (p[d] <= 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    s[0] = p[0] = 1;
    rep1(d,n){
        p[d] = min(p[d-1]*2 - a[d], p[d]);
        if (p[d] < 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << accumulate(all(p), 0LL) + accumulate(all(a), 0LL) << endl;
    return 0;
}
