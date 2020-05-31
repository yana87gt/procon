#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    ll n;
    cin >> n;
    ll r = sqrt(n);
    ll res = n;
    rep1(i,r){
        if (n%i==0) {
            res = min(res, n/i + i - 2);
        }
    }
    cout << res << endl;
    return 0;
}
