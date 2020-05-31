#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    int mx = 0;
    int cnt = 0;
    rep(i,n) {
        int h;
        cin >> h;
        if (mx <= h) cnt ++;
        mx = max(mx, h);
    }
    cout << cnt << endl;
    return 0;
}
