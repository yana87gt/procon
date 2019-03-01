#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll a,b,c;
    cin >> a >> b >> c;
    if (c <= a+b) {
        cout << b+c << endl;
    } else {
        cout << a+b+1 + b << endl;
    }
    return 0;
}
