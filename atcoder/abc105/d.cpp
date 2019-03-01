#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n;
    ll m;
    cin >> n >> m;
    map<ll,ll> mod;
    mod[0] = 1;
    ll res = 0;
    ll sum = 0;
    rep(i,n){
        ll a;
        cin >> a;
        sum += a;
        res += mod[sum%m]++;
    }
    cout << res << endl;
    return 0;
}
