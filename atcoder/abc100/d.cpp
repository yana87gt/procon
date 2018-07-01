#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

int main(void){
    int n,m;
    cin>>n>>m;
    vector<ll> x(n),y(n),z(n);
    rep(i,n) cin>>x[i]>>y[i]>>z[i];
    int s[2] = {-1,+1};
    ll res = -1e10;
    rep(sx,2)rep(sy,2)rep(sz,2){
        vector<ll> v;
        rep(i,n){
            v.push_back(x[i]*s[sx] + y[i]*s[sy] + z[i]*s[sz]);
        }
        sort(all(v),greater<ll>());
        res = max(res,accumulate(v.begin(),v.begin()+m,0LL));
    }
    cout<<res<<endl;
    return 0;
}
