#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int N;
    cin>>N;
    vector<ll> a(N),b(N);
    rep(i,N){
        cin>>a[i];
    }
    ll sum=0;
    rep(i,N){
        sum += a[i];
        b[i] = sum;
    }

    ll res = INT_MAX;
    rep(i,N-1){
        res = min(res,abs(sum-2*b[i]));
    }
    cout<<res<<endl;
    return 0;
}
