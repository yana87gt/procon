#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    sort(all(h));
    ll sum = 0;
    rep(i, n-k) sum += h[i];
    cout << sum << endl;
    return 0;
}
