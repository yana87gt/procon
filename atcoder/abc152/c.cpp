#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    int m = n+1;
    int cnt = 0;
    rep(i,n) {
        int p;
        cin >> p;
        if (m >= p) {
            m = p;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
