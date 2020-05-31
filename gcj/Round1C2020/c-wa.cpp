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

#define debug(x) cerr<<(#x)<<": "<<(x)<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

template<typename T>
map<T,int> factorize(T x){
    map<T,int> mp;
    for (T i = 2; i*i <= x; i++){
        while (x%i == 0) {
            x /= i;
            mp[i]++;
        }
        if (x == 1) break;
    }
    if (x != 1) mp[x]++;
    return mp;
}


void dfs(map<ll,int> &mp, map<ll,int>::iterator itr, ll pi, vector<ll> &divs){
    if (itr == mp.end()) {
        divs.push_back(pi);
        return;
    }
    ll pr = 1;
    rep(r,itr->second + 1){
        ++itr;
        dfs(mp, itr, pi * pr, divs);
        --itr;
        pr *= itr->first;
    }
}

vector<ll> get_divisors(map<ll,int> mp){
    vector<ll> divs;
    dfs(mp, mp.begin(), 1, divs);
    return divs;
}



void solve(){
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    set<ll> divs;
    rep(i,n) {
        cin >> a[i];
        a[i] *= d;
        auto ds = get_divisors(factorize(a[i]));
        // debug(a[i]);
        // print(ds);
        for (ll x : ds) {
            divs.insert(x);
        }
    }
    sort(all(a));
    // print(a);
    // print(divs);
    ll res = d-1;
    for (ll x : divs) {
        vector<ll> b;
        rep(i,n) {
            if (a[i] % x == 0) {
                b.push_back(a[i]);
            }
        }
        ll cut = 0, piece = 0;
        rep(i,b.size()) {
            if (piece + b[i]/x > d) {
                cut += d - piece;
            } else {
                cut += b[i]/x - 1;
            }
            piece += b[i]/x;
            if (piece >= d) break;
        }
        if (piece >= d) {
            res = min(res, cut);
        } else {
            cut += d-piece;
            res = min(res, cut);
        }
        // debug(x);
        // print(b);
        // debug(cut);
    }
    cout << res << endl;
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        solve();
    }
    return 0;
}
