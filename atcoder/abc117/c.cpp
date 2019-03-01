#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> x(m),d(m-1);
    rep(i,m) cin >> x[i];
    sort(all(x));
    rep(i,m-1){
        d[i] = x[i+1] - x[i];
    }
    sort(all(d));
    ll sum = 0;
    rep(i, max(m-n,0)){
        sum += d[i];
    }
    cout << sum << endl;
    return 0;
}
