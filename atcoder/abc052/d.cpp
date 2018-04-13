#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n;
    ll a,b;
    cin>>n>>a>>b;
    vector<ll> x(n);
    rep(i,n){
        cin>>x[i];
    }
    ll res = 0;
    rep(i,n-1){
        res += min((x[i+1]-x[i])*a, b);
    }
    cout<<res<<endl;
    return 0;
}
