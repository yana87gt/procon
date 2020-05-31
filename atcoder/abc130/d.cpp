#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define lb(s,x) (lower_bound(all(s),x)-s.begin())

template<typename T>
vector<T> cumulative_sum(vector<T> &v) {
    vector<T> sum(v.size() + 1);
    rep(i,v.size()){
        sum[i+1] = sum[i] + v[i];
    }
    return sum;
}

int main(void){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    auto cum = cumulative_sum(a);
    ll res = 0;
    rep(i,n){
        res += n+1 - lb(cum, cum[i]+k);
    }
    cout << res << endl;
    return 0;
}
