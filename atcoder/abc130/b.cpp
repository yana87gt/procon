#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,x;
    cin >> n >> x;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    int d = 0, cnt = 1;
    rep(i,n){
        d = d + l[i];
        if (d <= x) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
