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
    int n,m;
    cin >> n >> m;
    map<ll, ll> mp;
    rep(i,n) {
        ll a;
        cin >> a;
        mp[a]++;
    }
    rep(i,m){
        ll b,c;
        cin >> b >> c;
        mp[c] += b;
    }
    ll sum = 0;
    for(auto itr = mp.rbegin(); itr != mp.rend(); ++itr) {
        ll num = itr->first;
        ll cnt = itr->second;
        if (cnt > n) {
            sum += num * n;
            break;
        }
        sum += num * cnt;
        n -= cnt;
    }
    cout << sum << endl;
    return 0;
}
