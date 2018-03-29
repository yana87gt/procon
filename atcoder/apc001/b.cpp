#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    ll diff = 0, add = 0;
    rep(i,n) {
        if(a[i] > b[i]){
            diff += a[i] - b[i];
        }else{
            add += (b[i]-a[i]+1)/2;
            if((b[i]-a[i])&1) diff++;
        }
    }
    cout<<(diff<=add ? "Yes" : "No")<<endl;
}
