#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

int main(void){
    int n;
    cin >> n;
    VP ps(n);
    vector<double> dx(n), dy(n);
    rep(i,n) {
        double x,y;
        char ch;
        cin >> x >> y >> ch;
        ps[i] = Point(x,y);
        if (ch == 'R') dx[i] = +1.0;
        if (ch == 'L') dx[i] = -1.0;
        if (ch == 'U') dy[i] = +1.0;
        if (ch == 'D') dy[i] = -1.0;
    }
    double l = 0, r = 1e9;
    auto area = [&](double t) {
        double minX = 1e9, minY = 1e9, maxX = -(1e9), maxY = -(1e9);
        rep(i,n){
            double x = ps[i].X + dx[i]*t;
            double y = ps[i].Y + dy[i]*t;
            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, x);
            maxY = max(maxY, y);
        }
        return (maxX - minX) * (maxY - minY);
    };
    rep(loop,500){
        double m1 = (l*2.0 + r)/3.0;
        double m2 = (l + r*2.0)/3.0;
        if (area(m1) <= area(m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }
    printf("%.15f\n", area((l+r)/2.0));
    return 0;
}
