#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    double n;
    cin >> n;
    rep(i,50000){
        if (int(i*1.08) == n){
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}
