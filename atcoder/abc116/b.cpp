#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x) {
    return (x%2 == 0) ? x/2 : x*3+1;
}

int main(void){
    ll cur;
    cin >> cur;
    map<ll, int> mp;
    mp[cur] = 1;
    int i = 1;
    while(true){
        i++;
        ll nxt = f(cur);
        if (mp[nxt]) {
            cout << i << endl;
            return 0;
        }
        mp[nxt] = i;
        cur = nxt;
    }

    return 0;
}
