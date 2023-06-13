#include <bits/stdc++.h>
using namespace std;

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

#define ll long long
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

int main(void) {
    int N;
    ll P, Q;
    cin >> N >> P >> Q;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    ll sum = 0;
    rep(p5,N)rep(p4,p5)rep(p3,p4)rep(p2,p3)rep(p1,p2){
        if (a[p1] * a[p2] % P * a[p3] % P * a[p4] % P * a[p5] % P == Q) {
            sum ++;
        }
    }
    cout << sum << endl;
    return 0;
}
