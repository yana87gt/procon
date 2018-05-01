#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
typedef long long ll;
#define mod ll(1e9+7)

ll f[1000010]={};

ll add(ll a,ll b){ return (a+b)%mod;}
ll mul(ll a,ll b){ return (a*b)%mod;}



ll fact(ll n){
    if(f[n]) return f[n];
    if(n==0) return 1;
    return f[n] = mul(n,fact(n-1));
}

ll power(ll n, ll r){
    if(r==0) return 1;
    return mul(power(mul(n,n),r/2),(r&1 ? n : 1));
}

ll divm(ll a,ll b){ return mul(a, power(b, mod-2));}

int main(void){
    int n;
    cin>>n;
    ll res = 0;

    // 最初の2以降がm個
    // score: m+1
    // 
    for(int m = (n-1)/2; m<=n-2 ; m++){
        debug(fact(m+1));
        debug(fact(n-m-2));
        ll tmp = mul(m+1, mul(fact(m+1), fact(n-m-2)));
        printf("%d: %lld\n",m,tmp/m+1);
        res = add(res, tmp);
    }
    cout<<res<<endl;
    return 0;
}
