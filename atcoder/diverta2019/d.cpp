#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    ll n;
    cin >> n;
    ll sum = 0;
    if(n != 1)rep1(y,sqrt(n)){
        if (n % y != 0) continue;
        ll x = (n/y)-1;
        if (n % x == y) {
            sum += x;
        }
    }
    cout << sum << endl;
    return 0;
}
