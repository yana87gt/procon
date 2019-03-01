#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

double a, b, c;
double f(double t) {
    return a*t + b*sin(c*t*acos(-1));
}
bool over(double t) {
    return f(t) > 100;
}

int main(void){
    cin >> a >> b >> c;
    double l = 0, r = 1000;
    rep(loop,200){
        double m = (l+r)/2;
        if(over(m)) r = m;
        else l = m;
    }
    printf("%.20f\n", l);
    return 0;
}
