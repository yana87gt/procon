#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
const double EPS = 1e-4;
typedef long long ll;
typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

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

namespace std {
  bool operator<(const Point a, const Point b) {
    return a.Y != b.Y ? a.Y < b.Y : a.X < b.X;
  }
}

// 凸包
VP convexHull(VP ps) {  // 元の点集合がソートされていいならVP&に
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  VP ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) == -1) --k;  // 余計な点も含むなら == -1 とする
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) == -1) --k;
  ch.resize(k-1);
  return ch;
}

int main(void){
    int n;
    double x,y;
    cin>>n;
    VP ps(n);
    rep(i,n){
        cin>>x>>y;
        ps[i] = {x,y};
    }

    ps = convexHull(ps);
    n = ps.size();
    cout<<n<<endl;
    rep(i,n){
        printf("%.0f %.0f\n",ps[i].X,ps[i].Y);
    }
    return 0;
}
