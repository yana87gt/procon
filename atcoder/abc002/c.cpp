#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

double cross(Point a, Point b) {
    return a.X*b.Y - a.Y*b.X;
}

double area(const VP& ps) {
    double a = 0;
    rep (i, ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
    return a / 2;
}

int main(void){
    VP ps;
    rep(i,3){
        double x,y;
        cin >> x >> y;
        ps.push_back(Point(x,y));
    }
    printf("%.5f\n", abs(area(ps)));
    return 0;
}
