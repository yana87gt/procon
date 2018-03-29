#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
#define mod ll(1e9+7)
ll mul(ll a,ll b){ return a*b%mod; }

ll solve(vector<ll> &v,int n){
    ll sum = 0;
    rep(i,n-1) sum += mul(v[i+1]-v[i],mul(i+1,n-i-1));
    return sum % mod;
}

int main(void){
    int n,m;
    cin>>n>>m;
    vector<ll> x(n),y(m);
    rep(i,n) cin>>x[i];
    rep(i,m) cin>>y[i];
    cout<<mul(solve(x,n),solve(y,m))<<endl;
    return 0;
}