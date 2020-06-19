#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int x,n;
    cin >> x >> n;
    vector<bool> is_p(101);
    rep(i,n) {
        int p;
        cin >> p;
        is_p[p] = true;
    }
    int res = -1;
    rep(i,102) {
        if (abs(x-i) < abs(res-x) && !is_p[i]) {
            res = i;
        }
    }
    cout << res << endl;
    return 0;
}
