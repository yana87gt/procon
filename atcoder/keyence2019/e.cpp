#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define lb(s,x) (lower_bound(all(s),x)-s.begin())
#define ub(s,x) (upper_bound(all(s),x)-s.begin())
#define uniq(a) a.erase(unique(all(a)),a.end())
#define bit(k) (1LL<<(k))
const int INF = 1e9;

#define debug(x) cerr<<(#x)<<": "<<(x)<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }


int main(void){
    int n;
    ll D;
    cin >> n >> D;
    vector<ll> a(n);
    rep(i,n) cin>> a[i];
    ll res = accumulate(all(a), 0LL) - *min_element(all(a));
    vector<ll> lmin(n);
    vector<ll> rmin(n);

    lmin[0] = 1e18;
    rmin[n-1] = 1e18;
    ll mn = a[0];
    rep1(i,n-1){
        mn += D;
        lmin[i] = mn;
        if (mn > a[i]) mn = a[i];
    }
    mn = a[n-1];
    for(int i = n-2; i>=0 ; i--){
        mn += D;
        rmin[i] = mn;
        if (mn > a[i]) mn = a[i];
    }
    rep(i,n) {
        res += min(lmin[i],rmin[i]);
    }
    cout << res <<endl;
    return 0;
}
