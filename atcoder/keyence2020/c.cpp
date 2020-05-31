#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    ll n, k, s;
    cin >> n >> k >> s;
    vector<ll> res(k,s);
    rep(i,n-k) {
        res.push_back(n < s ? 1 : 1e9);
    }
    rep(i,n){
        cout << res[i] << (i < n-1 ? " " : "\n");
    }
    return 0;
}
