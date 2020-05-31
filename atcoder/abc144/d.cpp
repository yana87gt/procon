#include <bits/stdc++.h>
using namespace std;

int main(void){
    double a,b,x;
    cin >> a >> b >> x;
    x /= a;
    double PI = acos(-1);
    double t1 = atan(2.0/a * (b - x/a));
    double t2 = atan(b*b/(2*x));
    printf("%.10f\n", (b <= a * tan(t2) ? t2 : t1) * 180.0/PI);
    return 0;
}
