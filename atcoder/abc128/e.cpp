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
    int n,q;
    cin >> n >> q;
    vector<ll> s(n),t(n),x(n);
    using P = pair<ll, pair<ll,ll>>;
    vector<P> vp(n);
    rep(i,n){
        ll s_, t_, x_;
        cin >> s_ >> t_ >> x_;
        vp[i] = {x_, {s_, t_}};        
    }
    sort(all(vp));
    rep(i,n){
        s[i] = vp[i].second.first;
        t[i] = vp[i].second.second;
        x[i] = vp[i].first;
    }
    vector<ll> d(q);
    map<ll, int> mp;
    rep(i,q) {
        cin >> d[i];
        mp[-d[i]] = i;
    }

    vector<ll> res(q, -1);
    rep(i,n){
        auto itr = mp.upper_bound(x[i]-t[i]);
        vector<ll> kills;
        while (itr != mp.end()) {
            if (x[i]-s[i] < itr->first) break;

            kills.push_back(itr->first);
            res[itr->second] = x[i];
            ++itr;
        }
        for(ll kill : kills){
            mp.erase(kill);
        }
    }
    rep(i,q){
        cout << res[i] << endl;
    }

    return 0;
}
