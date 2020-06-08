#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
const int INF = 1e9;

int main(void){
    ll a, r, n;
    cin >> a >> r >> n;
    if (r == 1) {
        cout << a << endl;
    } else if (n > 30) {
        cout << "large" << endl;
    } else {
        rep(i,n-1) {
            a *= r;
            if (a > INF) {
                cout << "large" << endl;
                return 0;
            }
        }
        cout << a << endl;
    }
    return 0;
}
