#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

/* 基本要素 */
typedef complex<double> Point;  // Point
typedef vector<Point> VP;
const double EPS = 1e-6;    // 許容誤差。問題によって変える

//小文字x,yだと他の変数x,yと衝突してしまうので大文字
#define X real()
#define Y imag()

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

double distSP(Point a1, Point a2, Point p) {
  Point r = proj(a1, a2, p);
  if (!ccw(a1, a2, r)) return abs(r-p);
  return min(abs(a1-p), abs(a2-p));
}

// 頂点の順序（sortやmax_elementに必要）
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

// 凸多角形の内部判定　O(n)
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inConvex(Point p, const VP& ps) {
  int n = ps.size();
  int dir = ccw(ps[0], ps[1], p);
  rep (i, n) {
    int ccwc = ccw(ps[i], ps[(i + 1) % n], p);
    if (!ccwc) return 2;  // 線分上に存在
    if (ccwc != dir) return 0;
  }
  return 1;
}

const double INF = 1e9;

int main(void){
	int N;
	while(cin>>N,N){
		vector<int> NV(N+2),H(N+2);
		vector<VP> vp(N+2,VP());
		rep(i,N){
			cin>>NV[i]>>H[i];
			vp[i] = VP(2*NV[i]);		
			rep(j,NV[i]){
				double x,y;
				cin>>x>>y;
				vp[i][j]={x,y};
			}
		}
		
		double theta,phi,sx,sy,tx,ty;
		cin>>theta>>phi>>sx>>sy>>tx>>ty;
		theta *= M_PI/180.0;
		phi   *= M_PI/180.0;

		rep(i,N){
			rep(j,NV[i]){
				vp[i][j+NV[i]] = vp[i][j] - polar(H[i]/tan(phi),theta);
			}
			vp[i] = convexHull(vp[i]);
		}

		N += 2;
		vp[N-1] = {{sx,sy}};
		vp[N-2] = {{tx,ty}};
	
		vector<vector<double>> d(N,vector<double>(N,INF));
		rep(i,N)rep(j,vp[i].size()){
			rep(k,N-2)rep(l,vp[k].size()){
				//凸包iの点j（もしくは点s,t）と 凸包kの辺(l,l+1) の距離
				d[i][k] = d[k][i] = 
					min(d[i][k],distSP(vp[k][l], vp[k][(l+1)%vp[k].size()], vp[i][j]));
			}
			rep(k,N-2){
				//凸包iの点j（もしくは点s,t）が 凸包kの内部にいる
				if(inConvex(vp[i][j], vp[k])){
					d[i][k] = d[k][i] = 0;
				}
			}
		}

		rep(k,N)rep(i,N)rep(j,N)
			d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

		printf("%.9f\n",min(d[N-1][N-2],abs(vp[N-1][0]-vp[N-2][0])));
	}
	return 0;
}
