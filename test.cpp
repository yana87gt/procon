#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-9;
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define ps_edge(PS,i) PS[i],PS[(i+1)%PS.size()]

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

// 2円の交点(自作)
VP crosspointCC(Point a, double ar, Point b, double br){
  double d = abs(b-a);
  if(abs(ar-br)>d || abs(ar+br)<d) return {};
  double t = acos(double((d*d+ar*ar-br*br)/(2*d*ar)));
  Point p1 = a+polar(ar,arg(b-a)+t);
  Point p2 = a+polar(ar,arg(b-a)-t);
  if(abs(p1-p2) < EPS) return {p1};
  return {p1,p2};
}

int main(void){
    VP vp = {{1000,500},{1000,515-3}};
    VP cp = crosspointCC(vp[0],10,vp[1],5);
    for(auto p:cp){
        cout<<p<<endl;
    }

    return 0;
}
