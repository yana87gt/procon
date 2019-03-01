#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc(ll a, ll b) {
    if (b == 0) return -a;
    return (a/b)*b*2 + calc(b, a%b);
}

int main(void){
    ll n,x;
    cin >> n >> x;
    ll a = max(n-x,x);
    ll b = min(n-x,x);
    cout << n + calc(a,b) << endl;
    return 0;
}
