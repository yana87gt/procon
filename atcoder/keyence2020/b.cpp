#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

const ll INF = 1e11;
using P = pair<ll, ll>;

int main(void){
    int n;
    cin >> n;
    vector<P> v(n);
    rep(i,n){
        ll x,l;
        cin >> x >> l;
        v[i] = {x+l, x-l};
    }
    sort(all(v));
    int cnt = 0;
    ll r = -INF;
    rep(i,n){
        if (r <= v[i].second) {
            r = v[i].first;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
