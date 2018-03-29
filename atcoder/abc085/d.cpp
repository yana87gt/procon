#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n,h;
    cin>>n>>h;
    vector<ll> b(n);
    ll amax=0,cnt=0;
    rep(i,n){
        ll a;
        cin>>a>>b[i];
        amax = max(amax,a);
    }
    sort(b.begin(),b.end(),greater<ll>());
    rep(i,n){
        if(b[i] < amax)break;
        h -= b[i];
        cnt++;
        if(h<=0)break;
    }
    if(h>0) cnt += h/amax + (h%amax>0);
    cout<<cnt<<endl;
}
