#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

const ll MOD = 1e9+7;

int main(void){
    int N;
    cin>>N;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    reverse(all(a));

    ll d=1,res=0;
    rep(i,N){
        res = (res+d*a[i])%MOD;
        for(int k=1;k<=a[i];k*=10)d = (d*10)%MOD;
    }
    cout<<res<<endl;

    return 0;
}
