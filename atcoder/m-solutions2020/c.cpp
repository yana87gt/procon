#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;


int main(void) {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    rep(i,n-k){
        cout << ((a[i] < a[i+k]) ? "Yes" : "No") << endl;
    }
    return 0;
}
