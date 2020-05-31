#include <bits/stdc++.h>
using namespace std;
int main(void){
    double pi = acos(-1);
    double a,b,h,m;
    cin >> a >> b >> h >> m;
    printf("%.20f\n", abs(polar(a, h*(pi/6) + (pi/6)*(m/60)) - polar(b, pi*2*(m/60))));
    return 0;
}
