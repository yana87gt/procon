#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
typedef long long ll;

bool check(ll n, ll k){
    if (n == 1) return true;
    if (n < k) return false;
    if (n % k == 0) {
        return check(n/k,k);
    } else {
        return check(n%k,k);
    }
}

vector<ll> get_div(ll n){
    vector<ll> res;
    for (ll d = 2; d*d <= n; d++) {
        if(n % d == 0){
            res.push_back(d);
            if (d < n/d) {
                res.push_back(n/d);
            }
        }
    }
    return res;
}

int main(void){
    ll n;
    cin >> n;
    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }
    vector<ll> cand = {n, n-1};
    auto div1 = get_div(n);
    cand.insert(cand.end(), all(div1));
    auto div2 = get_div(n-1);
    cand.insert(cand.end(), all(div2));
    set<ll> res;
    for (ll d : cand){
        if (check(n,d)) res.insert(d);
    }
    cout << res.size() << endl;
    return 0;
}
