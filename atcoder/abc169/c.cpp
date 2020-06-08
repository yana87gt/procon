#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll a, b, c;
    scanf("%lld %lld.%lld", &a, &b, &c);
    cout << a * (b*100+c) / 100 << endl;
    return 0;
}
