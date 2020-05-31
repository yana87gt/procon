#include <bits/stdc++.h>
using namespace std;

int main(void){
    int k, a, b;
    cin >> k >> a >> b;
    bool ok = false;
    for (int i = a; i <= b; i++) {
        if (i % k == 0) ok = true;
    }
    cout << ((ok) ? "OK" : "NG") << endl;
    return 0;
}
