#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll a, ll b, ll x) {
    return a*x/b - a * (ll)(x/b);
}

int main(void){
    ll a, b, n;
    cin >> a >> b >> n;
    cout << f(a,b,min(b-1,n)) << endl;
    return 0;
}
