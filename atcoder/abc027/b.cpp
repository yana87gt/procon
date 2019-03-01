#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int sum = accumulate(all(a), 0);
    if (sum % n != 0) {
        cout << -1 << endl;
        return 0;
    }
    int ave = sum/n;
    int cnt = 0;
    rep(i,n-1){
        if (a[i] > ave) {
            a[i+1] += a[i]-ave;
            a[i] = ave;
            cnt++;
        } else if (a[i] < ave) {
            a[i+1] -= ave-a[i];
            a[i] = ave;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
