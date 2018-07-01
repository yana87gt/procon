#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
const ll mod = 998244353;

vector<ll> f;

ll add(ll a,ll b){ return (a+b)%mod;}

ll sub(ll a,ll b){ return (a-b)%mod;}

ll mul(ll a,ll b){ return (a*b)%mod;}

ll power(ll n, ll r){
    if(r==0) return 1;
    return mul(power(mul(n,n),r/2),(r&1 ? n : 1));
}

ll divm(ll a,ll b){ return mul(a, power(b, mod-2));}

ll fact(ll n){
    if(f[n]) return f[n];
    if(n==0) return 1;
    return f[n] = mul(n,fact(n-1));
}

ll com(ll n,ll r){
    if(n<r) return 0;
    return divm(fact(n),mul(fact(n-r),fact(r)));
}

int main(void){
    ll N,A,B,K;
    cin>>N>>A>>B>>K;
    f.resize(N+1);
    ll res = 0;
    rep(a,N+1){
        if(A*a > K) break;
        if((K-A*a)%B == 0){
            ll b = (K-A*a)/B;
            res = add(res,mul(com(N,a),com(N,b)));
        }
    }
    cout<<res<<endl;

    return 0;
}
