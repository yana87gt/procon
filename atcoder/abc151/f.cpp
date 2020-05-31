#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

typedef complex<double> Point;
typedef vector<Point> VP;

// 点集合を含む最小の円の中心
Point minEnclosingCircle(const VP& ps) {
    Point c;
    double move = 0.5;
    rep(i,39) {  // 2^(-39-1) \approx 0.9e-12
        rep(t,100) {
            double max = 0;
            int k = 0;
            rep (j, ps.size()) if (max < norm(ps[j]-c)) {
                max = norm(ps[j]-c);
                k = j;
            }
            c += (ps[k]-c) * move;
        }
        move /= 2;
    }
    return c;
}


int main(void){
    int n;
    cin >> n;
    VP ps(n);
    rep(i,n){
        double x, y;
        cin >> x >> y;
        ps[i] = Point(x,y);
    }
    Point c = minEnclosingCircle(ps);
    double r = 0;
    rep(i,n){
        r = max(r, abs(c-ps[i]));
    }
    printf("%.10f\n",r);
    return 0;
}
