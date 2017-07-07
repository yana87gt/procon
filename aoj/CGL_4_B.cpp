#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}

// 凸多角形の直径（最遠点対）
pair<int, int> convexDiameter(const VP& ps) {
  int n = ps.size();
  int i = min_element(ps.begin(), ps.end()) - ps.begin();
  int j = max_element(ps.begin(), ps.end()) - ps.begin();
  int maxI, maxJ;
  double maxD = 0;
  rep(_, 2*n) {
    if (maxD < norm(ps[i]-ps[j])) {
      maxD = norm(ps[i]-ps[j]);
      maxI = i;
      maxJ = j;
    }
    if (cross(ps[i]-ps[(i+1) % n], ps[(j+1) % n]-ps[j]) <= 0) j = (j+1) % n;
    else                                                      i = (i+1) % n;
  }
  return make_pair(maxI, maxJ);
}


int main(void){
    int n;
    double x,y;
    cin>>n;
    VP ch(n);
    rep(i,n){
        cin>>x>>y;
        ch[i] = {x,y};
    }

    pair<int,int> pp = convexDiameter(ch);
    printf("%.9f\n",abs(ch[pp.first]-ch[pp.second]));
    return 0;
}
