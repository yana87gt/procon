#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n;
    cin >> n;
    ll sum = 0;
    map<ll, int> cnt;
    rep(i,n){
        ll a;
        cin >> a;
        sum += a;
        cnt[a]++;
    }
    int Q;
    cin >> Q;
    rep(q,Q){
        ll b, c;
        cin >> b >> c;
        sum = sum - b*cnt[b] + c*cnt[b];
        cnt[c] += cnt[b];
        cnt[b] = 0;
        cout << sum << endl;
    }
    return 0;
}
