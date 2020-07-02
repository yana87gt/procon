#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define ub(s,x) (upper_bound(all(s),x)-s.begin())

template<typename T>
vector<T> cumulative_sum(vector<T> &v) {
    vector<T> sum(v.size() + 1);
    rep(i,v.size()){
        sum[i+1] = sum[i] + v[i];
    }
    return sum;
}


int main(void){
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    auto a_sum = cumulative_sum(a);
    auto b_sum = cumulative_sum(b);
    int res = 0;
    rep(i, a_sum.size()){
        ll rem = k - a_sum[i];
        if (rem < 0) break;
        int b_num = ub(b_sum, rem) - 1;
        res = max(res, i + b_num);
    }
    cout << res << endl;
    return 0;
}
