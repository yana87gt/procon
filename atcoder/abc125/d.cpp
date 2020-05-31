#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
const int INF = 1e9;

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    int minus_cnt = 0;
    ll abs_sum = 0;
    ll abs_min = INF;
    rep(i,n) {
        cin >> a[i];
        if (a[i] < 0LL) minus_cnt++;
        abs_min = min(abs_min, abs(a[i]));
        abs_sum += abs(a[i]);
    }
    if (minus_cnt % 2 == 0) {
        cout << abs_sum << endl;
    } else {
        cout << abs_sum - abs_min*2 << endl;
    }
    return 0;
}
