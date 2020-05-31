#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    /*
    Al + Ar = r-l
    Al + l = r - Ar
    b[i] = Ai + i;
    cnt[i - A[i]]++;
    */
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    map<ll, ll> cnt;
    rep(i,n) {
        cin >> a[i];
        b[i] = a[i] + i;
        cnt[i - a[i]]++;
    }
    ll res = 0;
    rep(i,n){
        res += cnt[b[i]];
    }
    cout << res << endl;
    return 0;
}
