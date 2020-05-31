#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> b(n),l(n),r(n);
    rep(i,n){
        cin >> b[i] >> l[i] >> r[i];
    }

    vector<int> ord(n);
    iota(all(ord), 0);
    auto cosper = [&](int i){
        return r[i]*(x-b[i]) + b[i]*l[i];
    };
    sort(all(ord), [&](int i, int j){
        return cosper(i) > cosper(j);
    });


    ll L = -1, R = x*n;
    while (L+1 < R) {
        ll M = (L+R)/2;
        auto win = [&](ll k) {
            ll sumA = 0, sumB = 0;
            ll q = k/x, rem = k%x;
            rep(ii,q){
                int i = ord[ii];
                sumA += r[i] * x;
                sumB += r[i] * b[i];
            }
            for (int ii = q; ii < n; ++ii) {
                int i = ord[ii];
                sumB += l[i] * b[i];
            }
            if (q < n && rem > 0) {
                rep(ii,n) {
                    int i = ord[ii];
                    ll A, B;
                    if (ii < q) {
                        A = sumA + (r[ord[q]] - r[i]) * x;
                        B = sumB + r[ord[q]] * b[ord[q]] - r[i] * b[i];
                    } else {
                        A = sumA;
                        B = sumB - l[i] * b[i];
                    }
                    if (rem <= b[i]) {
                        A += l[i] * rem;
                        B += l[i] * b[i];
                    } else {
                        A += r[i] * rem;
                        B += r[i] * b[i];
                    }
                    if (A >= B) {
                        return true;
                    }
                }
                return false;
            } else {
                return sumA >= sumB;
            }
        };
        if (win(M)) R = M;
        else L = M;
    }
    cout << R << endl;

    return 0;
}
