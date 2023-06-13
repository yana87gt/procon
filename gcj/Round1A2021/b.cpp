#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

void solve() {
    int M;
    cin >> M;
    vector<ll> P(M), N(M);
    ll all_sum = 0;
    rep(i,M) {
        cin >> P[i] >> N[i];
        all_sum += P[i] * N[i];
    }

    ll max_score = 0;
    for (ll sum_factors = 2; sum_factors <= min(all_sum - 2, 5000LL); ++sum_factors) {
        ll x = all_sum - sum_factors;
        vector<ll> factors;
        rep(i,M) {
            rep(j,N[i]) {
                if (x % P[i] == 0) {
                    x /= P[i];
                    factors.push_back(P[i]);
                } else {
                    break;
                }
            }
        }
        if (x == 1 && accumulate(factors.begin(), factors.end(), 0LL) == sum_factors) {
            max_score = all_sum - sum_factors;
            break;
        }
    }
    cout << max_score << endl;
}

int main(void) {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t){
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
