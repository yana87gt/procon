#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

vector<ll> get_acum(vector<ll> v){
    int V = v.size();
    vector<ll> acum = {0LL};
    rep(i,V){
        ll x = v[i] + acum.back();
        acum.push_back(x);
    }
    return acum;
}

int main(void){
    int x,y,A,B,C;
    cin >> x >> y >> A >> B >> C;
    vector<ll> a(A), b(B), c(C);
    rep(i,A) cin >> a[i];
    rep(i,B) cin >> b[i];
    rep(i,C) cin >> c[i];
    sort(all(a), greater<ll>());
    sort(all(b), greater<ll>());
    sort(all(c), greater<ll>());
    vector<ll> ab;
    rep(i,x) ab.push_back(a[i]);
    rep(i,y) ab.push_back(b[i]);
    sort(all(ab), greater<ll>());
    auto ab_acum = get_acum(ab);
    auto c_acum = get_acum(c);
    ll res = 0;
    rep(z,C+1){
        int n = x+y-z;
        if (n < 0) continue;
        res = max(res, c_acum[z] + ab_acum[n]);
    }
    cout << res << endl;
    return 0;
}
