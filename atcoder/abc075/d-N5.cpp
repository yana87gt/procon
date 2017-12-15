#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
#define x first
#define y second

int main(void){
    int N,K;
    cin>>N>>K;
    vector<pair<ll,ll>> p(N);
    rep(i,N) cin>>p[i].x>>p[i].y;
    ll res = LLONG_MAX;
    rep(a,N)rep(b,N)rep(c,N)rep(d,N){
        ll L = min({p[a].x, p[b].x, p[c].x, p[d].x});
        ll R = max({p[a].x, p[b].x, p[c].x, p[d].x});
        ll D = min({p[a].y, p[b].y, p[c].y, p[d].y});
        ll U = max({p[a].y, p[b].y, p[c].y, p[d].y});
        int cnt=0;
        rep(i,N) if(L<=p[i].x && p[i].x<=R && D<=p[i].y && p[i].y<=U)
            cnt++;
        if(cnt>=K) res = min(res,(R-L)*(U-D));
    }
    cout<<res<<endl;
}
