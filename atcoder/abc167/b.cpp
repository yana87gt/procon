#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll res = 0;
    res += min(a,k);
    k -= min(a,k);
    k -= min(b,k);
    res -= min(k,c);
    cout << res << endl;
    return 0;
}
