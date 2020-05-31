#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
const double PI = acos(-1);

typedef complex<double> Point;
typedef vector<Point> VP;

int main(void){
    int n;
    cin >> n;
    VP ps(n);
    rep(i,n){
        double x,y;
        cin >> x >> y;
        ps[i] = Point(x,y);
    }
    double M = 1000;
    double res = 0;
    rep(i,M){
        Point inf = polar(1e9, 2.0*PI*(i/M));
        VP used;
        Point p(0,0);
        rep(j,n){
            if (abs(ps[j]-inf) < 1e9) {
                p += ps[j];
            }
        }
        res = max(res, abs(p));
    }
    printf("%.20f\n", res);
    return 0;
}
