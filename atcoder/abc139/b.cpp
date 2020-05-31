#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b;
    cin >> a >> b;
    if (b == 1) {
        cout << 0 << endl;
        return 0;
    }
    int cnt = 1;
    b -= a;
    while (b > 0) {
        b -= a-1;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
