#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl
#define rep(i,n) for(int i=0;i<n;++i)
#define EPS 1e-9
typedef complex<double> Point;
typedef vector<Point> VP;
typedef pair<Point, Point> Line;
#define X real()
#define Y imag()
#define EQ(n,m) (abs((n)-(m)) < EPS)

namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}

double dot(Point a, Point b) {
  return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

int main(void){
    int n;
    while(cin>>n,n){
        vector<Line> ls(n);
        int crosscnt=0;
        rep(i,n){
            double p1x,p1y,p2x,p2y;
            cin>>p1x>>p1y>>p2x>>p2y;
            ls[i] = {{p1x,p1y},{p2x,p2y}};
            set<Point> cp;
            rep(j,i){
                if(isecSS(ls[i].first,ls[i].second,ls[j].first,ls[j].second)){
                    Point p = crosspointLL(ls[i].first,ls[i].second,ls[j].first,ls[j].second);
                    if(abs(p.X)<100 && abs(p.Y)<100) cp.insert(p);
                }
            }
            crosscnt += (int)cp.size();
        }
        cout<<n+crosscnt+1<<endl;
    }

    return 0;
}
