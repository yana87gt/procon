#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll x;
    cin >> x;
    int cnt = 0;
    ll atm = 100;
    while (atm < x) {
        atm *= 1.01;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
