#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) a.begin(),a.end()
typedef complex<double> Point;
typedef vector<Point> VP;
const double EPS = 1e-9;
#define X real()
#define Y imag()
#define EQ(n,m) (abs((n)-(m)) < EPS)

VP crosspointCC(Point a, double ar, Point b, double br) {
  VP ps;
  Point ab = b-a;
  double d = abs(ab);
  double crL = (norm(ab) + ar*ar - br*br) / (2*d);
  if (EQ(d, 0) || ar < abs(crL)) assert(false);

  Point abN = ab * Point(0, sqrt(ar*ar - crL*crL) / d);
  Point cp = a + crL/d * ab;
  ps.push_back(cp + abN);
  ps.push_back(cp - abN);
  return ps;
}

namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}


int main(void){
    double c1x,c1y,c1r,c2x,c2y,c2r;
    cin>>c1x>>c1y>>c1r>>c2x>>c2y>>c2r;
    VP ps = crosspointCC(Point(c1x,c1y),c1r,Point(c2x,c2y),c2r);
    sort(all(ps));
    printf("%.9f %.9f ", ps[0].X,ps[0].Y);
    printf("%.9f %.9f\n",ps[1].X,ps[1].Y);
    return 0;
}
