#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))

int main(void){
    int n,K;
    cin >> n >> K;
    vector<ll> a(n), sum(n+1);
    rep(i,n) cin>>a[i];
    rep(i,n) sum[i+1] += sum[i] + a[i];
    vector<ll> btf;
    rep1(r,n)rep(l,r){
        btf.push_back(sum[r]-sum[l]);
    }

    ll res = 0;
    for (int k = 60; k >= 0; k--) {
        sort(all(btf), greater<ll>());
        vector<ll> tmp;
        if (btf[K-1] & bit(k)) {
            res |= bit(k);
            for (ll b : btf) {
                if (b & bit(k)) {
                    tmp.push_back(b & (bit(k)-1));
                }
            }
        } else {
            for (ll b : btf) {
                tmp.push_back(b & (bit(k)-1));
            }
        }
        btf = tmp;
    }
    cout << res << endl;
    return 0;
}
