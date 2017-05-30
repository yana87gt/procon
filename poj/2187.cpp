#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

struct Point{
	double x,y;
	bool operator < (const Point &p)const{return x!=p.x ? x<p.x : y<p.y;}
	Point operator + (const Point &p)const{return {x+p.x,y+p.y};}
	Point operator - (const Point &p)const{return {x-p.x,y-p.y};}
	Point operator * (const double &k)const{return {k*x,k*y};}
	Point operator / (const double &k)const{return {x/k,y/k};}
};

typedef vector<Point> VP;
#define EPS 1e-7
// 内積　dot(a,b) = |a||b|cosθ
double dot(Point a, Point b) {return a.x*b.x+a.y*b.y;}
// 外積　cross(a,b) = |a||b|sinθ
double cross(Point a, Point b) {return a.x*b.y-a.y*b.x;}
double norm(Point p) {return p.x*p.x+p.y*p.y;}
double abs(Point p) {return sqrt(p.x*p.x+p.y*p.y);}


// 点の進行方向
int ccw(Point a, Point b, Point c) {
  b = b-a;  c = c-a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 凸包
VP convexHull(VP ps) {  // 元の点集合がソートされていいならVP&に
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  VP ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;  // 余計な点も含むなら == -1 とする
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}

// 凸多角形の直径（最遠点対）
double convexDiameter(VP ps) {
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
  return norm(ps[maxI]-ps[maxJ]);
}

int main(){
	int N;
	scanf("%d",&N);
	VP p(N);
	rep(i,N)scanf("%lf%lf",&p[i].x,&p[i].y);
	printf("%.0f\n",convexDiameter(convexHull(p)));
	return 0;
}