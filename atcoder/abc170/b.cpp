#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)


int main(void){
    int x,y;
    cin >> x >> y;
    bool yes = false;
    rep(a,100)rep(b,100){
        if (a+b == x && a*2 + b*4 == y) {
            yes = true;
        }
    }
    cout << ((yes) ? "Yes" : "No") << endl;
    return 0;
}
