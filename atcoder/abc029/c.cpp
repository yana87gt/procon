#include <bits/stdc++.h>
using namespace std;

void rec(string sub, int k){
    if (k == 0) {
        cout << sub << endl;
        return;
    }
    rec(sub+"a", k-1);
    rec(sub+"b", k-1);
    rec(sub+"c", k-1);
}

int main(void){
    int n;
    cin >> n;
    rec("", n);
    return 0;
}
