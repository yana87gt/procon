#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n,k;
    cin>>n>>k;
    map<int,ll> b,w;
    w[-1] = 1;
    ll sum = 0;
    rep(i,n){
        w[i] = b[i-1];
        b[i] = w[i-1] + w[i-k];
        sum += b[i];
    }
    cout<<sum<<endl;
    return 0;
}
