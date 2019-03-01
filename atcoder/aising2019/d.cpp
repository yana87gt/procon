#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int n;
vector<int> a;

// kを増やすべきかどうか
bool check(int x, int k){
    if (n-k <= n/2) return false;
    return abs(a[n-k*2-1]-x) <= abs(a[n-k-1]-x);
}

int main(void){
    int q;
    cin >> n >> q;
    a.resize(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n+1), t_sum(n+1);
    rep(i,n){
        sum[i+1] = sum[i] + a[i];
        if (i % 2 != n % 2) {
            t_sum[i+1] = t_sum[i] + a[i];
        } else {
            t_sum[i+1] = t_sum[i];
        }
    }
    rep(_,q){
        int x;
        cin >> x;
        int l = 0, r = n;
        while (l + 1 < r) {
            int m = (l+r)/2;
            if (check(x, m)) l = m;
            else r = m;
        }
        int k = r;
        cout << sum[n]-sum[n-k] + t_sum[max(n-2*k,0)]<< endl;
    }

    return 0;
}
