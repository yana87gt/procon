#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) a.begin(),a.end()
typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

double dot(Point a, Point b) {
  return a.X*b.X + a.Y*b.Y;
}

Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

VP crosspointLC(Point a1, Point a2, Point c, double r) {
  VP ps;
  Point ft = proj(a1, a2, c);
  assert(r*r >= norm(ft-c));
  Point dir = sqrt(max(r*r - norm(ft-c), 0.0)) / abs(a2-a1) * (a2-a1);
  ps.push_back(ft + dir);
  ps.push_back(ft - dir);
  return ps;
}

namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}

int main(void){
    double cx,cy,r;
    int q;
    cin>>cx>>cy>>r>>q;
    rep(i,q){
        double x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        VP ps = crosspointLC(Point(x1,y1),Point(x2,y2),Point(cx,cy),r);
        sort(all(ps));
        printf("%.9f %.9f " ,ps[0].X,ps[0].Y);
        printf("%.9f %.9f\n",ps[1].X,ps[1].Y);
    }
    return 0;
}
