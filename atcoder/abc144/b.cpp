#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    bool ok = false;
    for (int i = 1; i < 10; i++) {
        if (n%i==0 && n/i < 10) ok = true;
    }
    cout << ((ok) ? "Yes" : "No") << endl;
    return 0;
}
