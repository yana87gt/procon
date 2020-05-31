#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

ll f(ll x) {
    if (x == 1) return 1;
    return f(x/2) * 2 + 1;
}

int main(void){
    ll x;
    cin >> x;
    cout << f(x) << endl;
    return 0;
}

