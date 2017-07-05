#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

#define cv_edge(CV,i) CV[i],CV[(i+1)%CV.size()]

typedef complex<double> Point;  // Point
typedef vector<Point> VP;
const double EPS = 1e-3;    // 許容誤差。問題によって変える

#define X real()
#define Y imag()
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 内積　dot(a,b) = |a||b|cosθ
double dot(Point a, Point b) {
  return a.X*b.X + a.Y*b.Y;
}

// 外積　cross(a,b) = |a||b|sinθ
double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

// 点の進行方向
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}

// 凸包
VP convexHull(VP& ps) {  // 元の点集合がソートされていいならVP&に
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

// 凸多角形の内部判定　O(logn)
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inCcwConvex(const VP& ps, Point p) {
  int n = ps.size();
  Point g = (ps[0] + ps[n / 3] + ps[n*2 / 3]) / 3.0;
  if (g == p) return 1;
  Point gp = p - g;

  int l = 0, r = n;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    Point gl = ps[l] - g;
    Point gm = ps[mid] - g;
    if (cross(gl, gm) > 0) {
      if (cross(gl, gp) >= 0 && cross(gm, gp) <= 0) r = mid;
      else l = mid;
    }
    else {
      if (cross(gl, gp) <= 0 && cross(gm, gp) >= 0) l = mid;
      else r = mid;
    }
  }
  r %= n;
  double cr = cross(ps[l] - p, ps[r] - p);
  return EQ(cr, 0) ? 2 : cr < 0 ? 0 : 1;
}

// 線分と点
bool isecSP(Point a1, Point a2, Point b) {
  return !ccw(a1, a2, b);
}

int main(void){
	int N;
	cin>>N;
	VP ch;
	rep(i,N){
		string s;
		double x,y;
		cin>>s>>x>>y;
		if(s=="TARGET"){
			if(ch.size()>=3 && inCcwConvex(ch,{x,y})){
				cout<<"DANGER"<<endl;
			}else if(ch.size()==2 && isecSP(ch[0],ch[1],{x,y})){
				cout<<"DANGER"<<endl;
			}else{
				cout<<"SAFE"<<endl;
			}
		}else{
			if(ch.size()<3 || !inCcwConvex(ch,{x,y})){
				ch.push_back({x,y});
			}
			if(ch.size()>=3){
				ch = convexHull(ch);
				// for(auto p:ch)cout<<p;
				// cout<<endl;
			}
		}
	}
    return 0;
}
