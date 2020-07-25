#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void) {
    int n;
    cin >> n;
    int r = sqrt(n)+1;
    vector<int> cnt(n+1);
    rep1(x,r)rep1(y,r)rep1(z,r){
        int res = x*x + y*y + z*z + x*y + y*z + z*x;
        if (res <= n) cnt[res]++;
    }
    rep1(i,n){
        cout << cnt[i] << endl;
    }
    return 0;
}
