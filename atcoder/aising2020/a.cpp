#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int l,r,d;
    int cnt = 0;
    cin >> l >> r >> d;
    for (int i = l; i <= r; i++) {
        if (i % d == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
