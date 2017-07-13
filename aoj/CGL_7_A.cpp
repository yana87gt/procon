#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

typedef complex<double> Point;
typedef pair<Point, Point> Line;
const double EPS = 1e-5;
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

int main(void){
    double c1x,c1y,c1r,c2x,c2y,c2r;
    cin>>c1x>>c1y>>c1r>>c2x>>c2y>>c2r;
    cout<<tangentLines(Point(c1x,c1y),c1r,Point(c2x,c2y),c2r).size()<<endl;
    return 0;
}
