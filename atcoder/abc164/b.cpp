#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    string res = "";
    rep(i,200){
        if (i%2 == 0) {
            c -= b;
        } else {
            a -= d;
        }

        if (a <= 0) {
            res = "No";
            break;
        }
        if (c <= 0) {
            res = "Yes";
            break;
        }
    }
    cout << res << endl;
    return 0;
}
