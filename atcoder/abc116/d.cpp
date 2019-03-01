#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
using P = pair<ll,ll>;

template<typename T>
vector<T> cumulative_sum(vector<T> &v) {
    vector<T> sum(v.size() + 1);
    rep(i,v.size()){
        sum[i+1] = sum[i] + v[i];
    }
    return sum;
}

int main(void){
    int n;
    ll K;
    cin >> n >> K;
    vector<P> vp(n);
    rep(i,n) {
        ll t,d;
        cin >> t >> d;
        vp[i] = {d,t};
    }
    sort(all(vp),greater<P>());
    map<ll,bool> used;
    vector<ll> top, rem;
    rep(i,n) {
        ll t = vp[i].second;
        ll d = vp[i].first;
        if (used[t]) {
            rem.push_back(d);
        } else {
            used[t] = true;
            top.push_back(d);
        }
    }
    auto top_sum = cumulative_sum(top);
    auto rem_sum = cumulative_sum(rem);
    ll res = 0;
    for(ll x = 1; x <= K; x++){
        if (K < x) continue;
        if (x >= (ll)top_sum.size()) continue;
        if (K-x >= (ll)rem_sum.size()) continue;
        res = max(res, top_sum[x] + rem_sum[K-x] + x*x);
    }
    cout << res << endl;
    return 0;
}
