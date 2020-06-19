#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define lb(s,x) (lower_bound(all(s),x)-s.begin())


using P = pair<ll,ll>;
#define w first
#define v second

vector<P> all_enumerate(vector<P> vp, ll W, bool need_sort){
    int N = vp.size();
    vector<P> dp;
    for (int mask = 0; mask < (1<<N); mask++) {
        ll sumV = 0, sumW = 0;
        for (int i = 0; i < N; i++) {
            if (mask & (1<<i)) {
                sumV += vp[i].v;
                sumW += vp[i].w;
            }
        }
        if (sumW <= W) {
            dp.push_back({sumW, sumV});
        }
    }
    if (!need_sort) return dp;
    // V降順
    sort(dp.begin(), dp.end(), [](P a, P b){
        return a.v != b.v ? a.v > b.v : a.w < b.w;
    });
    vector<P> res;
    int w_border = W+1;
    for(P s : dp){
        if( w_border > s.w){
            w_border = s.w;
            res.push_back(s);
        }
    }
    // V昇順 & W昇順
    reverse(res.begin(), res.end());
    return res;
}

int main(void){
    cin.tie(0); ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n+1),w(n+1);
    rep1(i,n){
        cin >> v[i] >> w[i];
    }
    int H2 = log2(n)/2 + 3;
    vector<vector<P>> dp((1<<H2)+1);
    for (int i = 1; i < (1<<H2); i++) {
        if (i > n) break;
        vector<P> vp;
        int x = i;
        while(x) {
            vp.push_back({w[x], v[x]});
            x /= 2;
        }
        dp[i] = all_enumerate(vp, 100000LL, true);
    }
    int Q;
    cin >> Q;
    rep(q,Q){
        int x, L;
        cin >> x >> L;
        vector<P> vp;
        while((1<<H2) <= x) {
            vp.push_back({w[x], v[x]});
            x /= 2;
        }
        vector<P> dp1 = dp[x];
        vector<P> dp2 = all_enumerate(vp, L, false);
        ll max_v = 0;
        for (P p : dp2) {
            int pos = lb(dp1, P({L - p.w + 1, 0LL})) - 1;
            if (pos < 0) {
                if (p.w <= L) {
                    max_v = max(max_v, p.v);
                }
            } else {
                if (p.w + dp1[pos].w <= L) {
                    max_v = max(max_v, p.v + dp1[pos].v);
                }
            }
        }
        cout << max_v << endl;
    }
    return 0;
}


