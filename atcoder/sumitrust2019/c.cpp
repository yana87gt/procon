#include <bits/stdc++.h>
using namespace std;

int main(void){
    int x;
    cin >> x;
    int l = 0, r = 0;
    while(l <= x){
        if (l <= x && x <= r) {
            cout << 1 << endl;
            return 0;
        }
        l += 100;
        r += 105;
    }
    cout << 0 << endl;
    return 0;
}
