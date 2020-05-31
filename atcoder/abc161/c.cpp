#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void k_large(ll x, ll k){
    cout << min(x,(ll)abs(k-x)) << endl;
}

int main(void){
    ll n,k;
    cin >> n >> k;
    if (n > k) {
        k_large(n%k, k);
    } else {
        k_large(n, k);
    }
    return 0;
}
