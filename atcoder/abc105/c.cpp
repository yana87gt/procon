#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    ll n;
    cin >> n;
    string res;
    rep(i,32) {
        ll sign = (i%2==0 ? +1 : -1);
        if (n%(1LL<<(i+1))==0){
            res += "0";
        } else {
            res += "1";
            n -= sign * (1LL<<i);
        }
        if (n == 0) break;
    }
    reverse(all(res));
    cout << res << endl;
    return 0;
}
