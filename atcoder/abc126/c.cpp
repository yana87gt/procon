#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    ll n,k;
    cin >> n >> k;
    ll res = 0;
    rep1(i,n){
        int x = i;
        ll p = (1/n);
        while (x < k) {
            x *= 2;
            p /= 2;
        }
        res += p;
    }
    printf("%.20Lf\n", res);
    return 0;
}
