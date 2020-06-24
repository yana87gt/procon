#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    int all_xor = 0;
    rep(i,n) {
        cin >> a[i];
        all_xor ^= a[i];
    }
    rep(i,n){
        cout << (all_xor ^ a[i]) << (i < n-1? " " : "\n");
    }
    return 0;
}
