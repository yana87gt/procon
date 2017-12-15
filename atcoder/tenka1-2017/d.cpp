#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int N,K;
    cin>>N>>K;
    vector<ll> a(N),b(N);
    rep(i,N) cin>>a[i]>>b[i];
    
    ll res = 0;
    rep(i,N) if((K|a[i])==K) res += b[i];

    for(int r=0;(1<<r)<=K;r++){
        if((K&(1<<r)) == 0) continue;
        int Kr = K - (K%(1<<r)) - 1;
        ll sum = 0;
        rep(i,N) if((Kr|a[i])==Kr) sum += b[i];
        res = max(res,sum);
    }
    cout<<res<<endl;
}
