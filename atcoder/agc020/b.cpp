#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

void solve(){
    int k;
    cin>>k;
    vector<ll> a(k);
    rep(i,k) cin>>a[i];
    reverse(all(a));
    if(a[0] != 2) {
        cout<<-1<<endl;
        return;
    }
    ll l=2,r=2;
    rep(i,k){
        if(a[i]>r || l>r) {
            cout<<-1<<endl;
            return;
        }
        if(l%a[i]>0){
            l = l-l%a[i]+a[i];
        }
        r = r-r%a[i]+a[i]-1;
    }
    if(l>r) {
        cout<<-1<<endl;
        return;
    }
    cout<<l<<" "<<r<<endl;
}

int main(void){
    solve();
    return 0;
}