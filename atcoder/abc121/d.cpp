#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// = f(0,x)
ll f(ll x) {
    if (x < 0) return 0;
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x+1;
    if (x % 4 == 3) return 0;
    assert(false);
}

int main(void){
    ll a,b;
    cin >> a >> b;
    cout << (f(a-1)^f(b)) << endl;
    return 0;
}
