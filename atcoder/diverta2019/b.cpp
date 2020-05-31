#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    int cnt = 0;
    rep(i, 3010){
        rep(j, 3010){
            int k = (n - (i*a + j*b))/c;
            if (i*a + j*b + k*c == n) {
                cnt ++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
