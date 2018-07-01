#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define ub(s,x) upper_bound(all(s),x)-s.begin()
typedef long long ll;

int main(void){
    ll n,d;
    cin>>n>>d;
    vector<ll> x(n+1);
    rep(i,n) cin>>x[i];
    x[n] = 3e9;
    int l = 0, r = 0;
    ll res = 0, seg = 0;
    rep(i,n){
        while(l<i && x[l]+d<x[i]){
            int p = ub(x,x[l]+d);
            if(p<=r) seg -= r-p+1;
            l++;
        }
        while(r<n && x[r+1]<=x[i]+d){
            r++;
            int p = lb(x,x[r]-d)-1;
            if(l<=p) seg += p-l+1;
        }
        res += seg;
    }
    cout<<res<<endl;
    return 0;
}
