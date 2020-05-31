#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    int A,B,M;
    cin >> A >> B >> M;
    vector<ll> a(A), b(B);
    rep(i,A) cin >> a[i];
    rep(i,B) cin >> b[i];
    ll res = *min_element(all(a)) + *min_element(all(b));
    rep(i,M){
        ll x,y,c;
        cin >> x >> y >> c;
        x--, y--;
        res = min(res, a[x] + b[y] - c);
    }
    cout << res << endl;
    
    return 0;
}
