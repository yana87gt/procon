#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(ll x) {
    ll M = 4200;
    for (ll a = -M; a <= M; a++) {
        for (ll b = -M; b <= M; b++) {
            if ((a*a*a*a*a) - (b*b*b*b*b) == x) {
                cout << a << " " << b << endl;
                return;
            }
        }
    }
    assert(false);
}

int main(void){
    ll x;
    cin >> x;
    solve(x);
    return 0;
}
