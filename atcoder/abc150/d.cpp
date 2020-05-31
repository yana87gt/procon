#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

ll gcd(ll a,ll b){return b==0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(void){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        a[i] /= 2;
    }
    ll l = a[0];
    rep(i,n){
        l = lcm(l, a[i]);
        if (l > m) {
            cout << 0 << endl;
            return 0;
        }
    }
    rep(i,n){
        if ((l/a[i]) % 2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << (m/l + 1)/2 << endl;
    return 0;
}
