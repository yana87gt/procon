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
    int n,k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i,n){
        cin >> v[i];
    }

    ll res = 0;
    ll sumL = 0;
    vector<ll> negL;
    rep(l,n+1){
        if (l > 0){
            sumL += v[l-1];
            if (v[l-1] < 0) negL.push_back(v[l-1]);
        }

        ll sumR = 0;
        vector<ll> negR;
        rep(r,n+1){
            if (l + r > n) break;
            if (l + r > k) break;
            if (r > 0){
                sumR += v[n-r];
                if (v[n-r] < 0) negR.push_back(v[n-r]);
            }
            vector<ll> negs = negL;
            for (ll x: negR){
                negs.push_back(x);
            }
            sort(all(negs));
            int rem = k - (l + r);
            ll score = sumL + sumR - accumulate(negs.begin(), negs.begin() + min(rem, (int)negs.size()), 0LL);
            res = max(res, score);
        }
    }
    cout << res << endl;
    return 0;
}
