#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

ll gcd(ll a,ll b){return b==0 ? a : gcd(b,a%b);}

bool solve(ll a,ll b,ll c,ll d){
    if(a < b) return false;
    if(b > d) return false;
    if(b <= c) return true;
    ll g = gcd(b,d);
    return c >= b - g + a%g;
}

int main(void){
    ll T;
    cin>>T;
    rep(_,T){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<((solve(a,b,c,d)) ? "Yes" : "No")<<endl;
    }
    return 0;
}
