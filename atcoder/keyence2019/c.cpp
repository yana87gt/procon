#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    priority_queue<int> give;
    ll recv = 0, just = 0;
    if (accumulate(all(a),0LL) < accumulate(all(b),0LL)) {
        cout << -1 << endl;
        return 0;
    }
    rep(i,n) {
        if (a[i]>b[i]) give.push(a[i]-b[i]);
        if (a[i]<b[i]) recv += (b[i]-a[i]);
        if (a[i]==b[i]) just++;
    }
    while(recv>0) {
        recv -= give.top(); give.pop();
    }
    cout << n-just-(int)give.size() << endl;
    return 0;
}
