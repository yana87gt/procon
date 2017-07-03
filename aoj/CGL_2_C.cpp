#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef complex<double> Point;
#define X real()
#define Y imag()
const double EPS = 1e-9;
#define EQ(n,m) (abs((n)-(m)) < EPS)

double cross(Point a, Point b) {
    return a.X*b.Y - a.Y*b.X;
}

Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

int main(void){
    int q;
    cin>>q;
    rep(i,q){
        double x0,y0,x1,y1,x2,y2,x3,y3;
        cin>>x0>>y0>>x1>>y1>>x2>>y2>>x3>>y3;
        Point p=crosspointLL({x0,y0},{x1,y1},{x2,y2},{x3,y3});
        printf("%.9f %.9f\n",p.X,p.Y);
    }
    return 0;
}
