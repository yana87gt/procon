#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    double ave = 0;
    rep(i,n) ave += a[i];
    ave /= n;
    int idx = 0;
    rep(i,n) if(abs(ave - a[idx]) > abs(ave - a[i])) {
        idx = i;
    }
    cout << idx << endl;
    return 0;
}
