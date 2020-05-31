#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll n, a, b;
    cin >> n >> a >> b;
    ll d = abs(a-b);
    if (d % 2 == 0) {
        cout << d/2 << endl;
    } else {
        cout << min({a-1,b-1,n-a,n-b}) + (d-1)/2 + 1 << endl;
    }
    return 0;
}
