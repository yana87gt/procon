#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int cnt = 0;
    for(int i = 1; i < n-1; i++) {
        if (min({p[i-1], p[i], p[i+1]}) != p[i] &&
            max({p[i-1], p[i], p[i+1]}) != p[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
