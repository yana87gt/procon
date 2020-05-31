#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int far = a[0] + k - a[n-1];
    rep(i,n-1){
        far = max(far, a[i+1] - a[i]);
    }
    cout << k - far << endl;
    return 0;
}
