#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
#define bit(k) (1LL<<(k))

ll solve() {
    int n;
    cin >> n;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];
    ll X = 0;
    for (int i = 2; i < n; i++) {
        X ^= A[i];
    }
    if (A[0]+A[1] < X) return -1;
    // a+b = A[0]+A[1]
    // a^b = X
    // a+b = a^b + (a&b)*2
    // a&b = ((a+b) - (a^b))/2
    ll D = (A[0]+A[1] - X)/2;
    if (A[0] < D) return -1;
    ll a = D;
    for (int k = 60; k >= 0; k--) {
        if (((a|bit(k)) <= A[0]) && (bit(k)&X)) {
            a |= bit(k);
        }
    }
    if (a == 0) return -1;
    ll b = (A[0]-a+A[1]);
    if ((a&b) != D) return -1;
    return A[0]-a;
}

int main(void){
    cout << solve() << endl;
    return 0;
}
