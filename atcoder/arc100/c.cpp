#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

int n;
vector<ll> a;

ll calc(ll x){
    ll res = 0;
    rep(i,n){
        res += abs(a[i]-x);
    }
    return res;
}

int main(void){
    cin>>n;
    a.resize(n);
    rep(i,n){
        cin>>a[i];
        a[i] -= i+1;
    }
    sort(all(a));
    ll l = a[0], r = a[n-1];
    while(l + 2 < r){
        ll m1 = (l*2+r)/3, m2 = (l+r*2)/3;
        if(calc(m1) < calc(m2)) r = m2;
        else l = m1;
    }
    cout<<min({calc(l),calc((l+r)/2),calc(r)})<<endl;
    return 0;
}
