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

ll com[40][40] = {};

ll combination(ll n, ll r){
    if (com[n][r]) return com[n][r];
    if (r > n-r) return com[n][r] = combination(n, n-r);
    if (r == 0) return com[n][r] = 1;
    if (r == 1) return com[n][r] = n;
    return com[n][r] = com[n-1][r-1] + com[n-1][r];
}

void solve(){
    ll n;
    cin >> n;
    ll k = 0;
    rep(i,32){
        if (bit(i+1)-1 < n) k = i;
    }
    debug(k);
    ll rem = bit(k+1) - 1;
    debug(rem);

    set<ll> set1;
    vector<int> cand1;
    rep(i,3){
        cand1.push_back(com[k+1][i+1]);
    }
    sort(all(cand1), greater<ll>());
    for (ll x : cand1) {
        if (rem >= x) {
            set1.insert(x);
            rem-=x;
        }
    }
    

    // rep(i,n){

    // }
}

int main(void){
    rep(i,37) combination(37, i);

    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        solve();
    }
    return 0;
}
