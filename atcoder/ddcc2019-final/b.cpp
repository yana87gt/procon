#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    ll n, k, r;
    cin >> n >> k >> r;
    vector<int> res(n);
    rep(i,n){
        int m = n-i;
        if (r == 0) break;
        if (r > m-k) {
            res[i] = m;
            r -= m-k;
        } else {
            res[i+m-k-r] = m;
            r = 0;
            break;
        }
    }
    if (r > 0) {
        cout << "No Luck" << endl;
    } else {
        int c = 1;
        rep(i,n) {
            cout << (res[i] ? res[i] : c++) << (i < n-1 ? " " : "\n");
        }
    }
    return 0;
}
