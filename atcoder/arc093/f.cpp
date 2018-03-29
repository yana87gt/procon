#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;
#define mod ll(1e9+7)
int N,M;
vector<int> A;
vector<ll> f;

ll mul(ll a,ll b){ return (a*b)%mod;}
ll fact(ll n){
    if(f[n]) return f[n];
    if(n==1) return 1;
    if(n==0) return 1;
    return f[n] = mul(n,fact(n-1));
}

ll winA(int a){
    ll res = 0;
    return res;
}

int main(void){
    cin>>N>>M;
    f.resize((1<<N)+1);
    rep(i,M){
        cin>>A[i];
    }

    ll res = fact(1<<N);
    rep(i,M){
        res = (res+mod-winA(A[i]))%mod;
    }
    cout<<res<<endl;
    return 0;
}
