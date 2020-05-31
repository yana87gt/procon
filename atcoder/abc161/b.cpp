#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int sum = accumulate(all(a), 0);
    int cnt = 0;
    rep(i,n) {
        if (a[i]*(m*4) >= sum) cnt++;
    }
    cout << ((cnt >= m) ? "Yes" : "No") << endl;
    return 0;
}
