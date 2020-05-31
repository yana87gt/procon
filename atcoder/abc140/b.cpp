#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n-1);
    rep(i,n) {
        cin >> a[i];
        a[i]--;
    }
    rep(i,n) cin >> b[i];
    rep(i,n-1) cin >> c[i];
    int sum = accumulate(all(b),0);
    rep(i,n-1){
        if (a[i]+1 == a[i+1]) sum += c[a[i]];
    }
    cout << sum << endl;

    return 0;
}
