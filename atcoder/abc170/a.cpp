#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    rep(i,5){
        int x;
        cin >> x;
        if (x == 0) {
            cout << i + 1 << endl;
        }
    }
    return 0;
}
