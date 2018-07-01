#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

int main(void){
    ll n,q;
    cin>>n>>q;
    vector<ll> x(n);
    map<ll,ll> cnt, dist;
    rep(i,n){
        cin>>x[i];
        cnt[x[i]]++;
        dist[x[i]] += x[i];
    }
    cnt[-2e9]++;
    cnt[2e9]++;
    dist[-2e9] += 0;
    dist[2e9] += 2e9;

    ll pre = 0;
    for(auto itr : cnt){
        cnt[itr.first] += pre;
        pre += itr.second;
    }

    pre = 0;
    for(auto itr : dist){
        dist[itr.first] += pre;
        pre += itr.second;
    }

    rep(_,q){
        ll c,d;
        cin>>c>>d;
        printf("---------- c = %lld , d = %lld----------\n",c,d);
        int cntL = (--cnt.lower_bound(c-d))->second;
        int cntM = (--cnt.upper_bound(c))->second;
        int cntR = (--cnt.lower_bound(c+d+1))->second;
        int distL = (--dist.lower_bound(c-d))->second;
        int distM = (--dist.upper_bound(c))->second;
        int distR = (--dist.lower_bound(c+d+1))->second;
        ll res = 0;
        debug(cntR);
        debug(cntM);
        debug(cntL);
        debug(distR);
        debug(distM);
        debug(distL);
        debug(c*cntM);
        debug(distM-distL);
        debug(distR-distM);
        debug(cntR-cntL);
        res += c*cntM - distM-distL;
        res += distR-distM - c*cntM;
        res += d*(n-cntR-cntL);
        cout<<res<<endl;
    }
    return 0;
}
