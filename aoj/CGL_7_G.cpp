#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double EPS = 1e-9;
#define X real()
#define Y imag()
#define LE(n,m) ((n) < (m) + EPS)

vector<Line> tangentLines(Point a, double ar, Point b, double br) {
  vector<Line> ls;
  double d = abs(b-a);
  rep (i,2) {
    double sin = (ar - (1-i*2)*br) / d;
    if (!LE(sin*sin, 1)) break;
    double cos = sqrt(max(1 - sin*sin, 0.0));
    rep (j,2) {
      Point n = (b-a) * Point(sin, (1-j*2)*cos) / d;
      ls.push_back(Line(a + ar*n, b + (1-i*2)*br*n));
      if (cos < EPS) break;  // 重複する接線を無視（重複していいならこの行不要）
    }
  }
  return ls;
}

namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}

int main(void){
    double c1x,c1y,c1r,c2x,c2y,c2r;
    cin>>c1x>>c1y>>c1r>>c2x>>c2y>>c2r;
    vector<Line> ls = tangentLines(Point(c1x,c1y),c1r,Point(c2x,c2y),c2r);
    VP ps;
    for(auto l : ls){
        ps.push_back(l.first);
        ps.push_back(l.second);
    }
    sort(all(ps));
    ps.erase(unique(all(ps)),ps.end());

    for(auto p : ps){
        if(abs(abs(p-Point(c1x,c1y))-c1r)<EPS){
            printf("%.9f %.9f\n",p.X,p.Y );
        }
    }
    return 0;
}
