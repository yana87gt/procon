#include <bits/stdc++.h>
using namespace std;

int main(void) {
    long long a,b,c,d;
    cin >> a >>b >> c >> d;
    cout << max({a*c, a*d, b*c, b*d}) << endl;
    return 0;
}
