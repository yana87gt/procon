#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<int(n);++i)
const ll MOD = 1e9+7;

int main(void){
    ll res = 1;
    rep(i,3){
        int v;
        cin >> v;
        res = (res * v) % MOD;
    }
    cout << res << endl;
    return 0;
}
