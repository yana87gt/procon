#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll x = a[0];
    rep1(i,n-1){
        x = a[i] - x;
    }
    assert(x % 2 == 0);

    vector<ll> res(n);
    res[0] = x;
    rep1(i,n-1){
        res[i] = (a[i-1] - res[i-1]/2)*2;
    }
    rep(i,n){
        cout << res[i] << (i < n-1 ? " " : "\n");
    }

    return 0;
}
