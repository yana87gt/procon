#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    ll L;
    int n;
    cin >> L >> n;
    vector<ll> xr(n+2),xl(n+2),sumr(n+2),suml(n+2);
    rep1(i,n) cin >> xr[i];
    xr[n+1] = L;
    rep(i,n+2) xl[n+1-i] = L - xr[i];
    rep1(i,n+1) {
        sumr[i] = sumr[i-1] + xr[i]*2;
        suml[i] = suml[i-1] + xl[i]*2;
    }
    ll res = 0;
    rep(r,n+1){
        int l = n - r;
        res = max({res,
            suml[l] - suml[max(l-r-1,0)] + sumr[r] - sumr[max(r-l,0)] - xl[l],
            sumr[r] - sumr[max(r-l-1,0)] + suml[l] - suml[max(l-r,0)] - xr[r]
        });
    }
    cout << res << endl;
    return 0;
}
