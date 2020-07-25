#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    int cnt = 0;
    while (a >= b) {
        b *= 2;
        cnt++;
    }
    while (b >= c) {
        c *= 2;
        cnt++;
    }
    cout << ((cnt <= k) ? "Yes" : "No") << endl;
    return 0;
}
