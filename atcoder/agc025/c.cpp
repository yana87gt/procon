#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    vector<ll> l(n+1),r(n+1);
    rep(i,n) cin>>l[i]>>r[i];
    sort(all(l));
    sort(all(r));
    ll sum = 0;
    rep(i,n) sum += max(l[n-i] - r[i],0LL);
    cout<<sum*2<<endl;
    return 0;
}
