#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    bool ok = false;
    rep(i,100)rep(j,100){
        if (i*4 + j*7 == n) {
            ok = true;
        }
    }
    cout << ((ok) ? "Yes" : "No") << endl;
    return 0;
}
