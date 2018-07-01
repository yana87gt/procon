#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
    }
    int l = 0;
    ll sum = 0, bit = 0;
    ll res = 0;
    rep(r,n){
        sum += a[r];
        bit ^= a[r];
        while(l<=r && sum != bit){
            sum -= a[l];
            bit ^= a[l];
            l++;
        }
        res += r-l+1;
    }
    cout<<res<<endl;
    return 0;
}
