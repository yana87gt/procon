#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,k;
    cin >> a >> b >> k;
    int i = min(a,b);
    while(true){
        if (a%i == 0 && b%i == 0) {
            k--;
        }
        if (k == 0) {
            cout << i << endl;
            break;
        }
        i--;
    }
    return 0;
}
