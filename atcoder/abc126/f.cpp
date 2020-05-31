#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int m, k;
    cin >> m >> k;
    int n = 1 << m;
    if (k >= n || (m == 1 && k == 1)) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> v;
    if (m <= 1) {
        rep(i,m+1){
            v.push_back(i);
            v.push_back(i);
        }
    } else {
        v.push_back(k);
        rep(i,n){
            if (i == k) continue;
            v.push_back(i);
        }
        v.push_back(k);
        rep(i,n){
            int j = n-1-i;
            if (j == k) continue;
            v.push_back(j);
        }
    }
    rep(i,n*2){
        cout << v[i] << (i < n*2-1 ? " " : "\n");
    }
    return 0;
}
