#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    vector<int> v(n), c(n);
    rep(i,n) cin >> v[i];
    rep(i,n) cin >> c[i];
    int sum = 0;
    rep(i,n) {
        if (v[i] > c[i]) sum += v[i] - c[i];
    }
    cout << sum << endl;
    return 0;
}
