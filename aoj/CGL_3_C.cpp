#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

#define INF 1e9
const double EPS = 1e-4;
typedef long long ll;
typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define LE(n,m) ((n) < (m) + EPS)

double dot(Point a, Point b) {
  return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

// 多角形の内部判定
// 点が領域内部なら2、境界上なら1、外部なら0を返す
int inPolygon(const VP& ps, Point p) {
  int n = ps.size();
  bool in = false;
  rep (i, n) {
    Point a = ps[i] - p;
    Point b = ps[(i + 1) % n] - p;
    if (EQ(cross(a,b), 0) && LE(dot(a,b), 0)) return 1;
    if (a.Y > b.Y) swap(a,b);
    if ((a.Y*b.Y < 0 || (a.Y*b.Y < EPS && b.Y > EPS)) && LE(cross(a, b), 0)) in = !in;
  }
  return (in ? 2 : 0);
}

int main(void){
    int n,q;
    double x,y;
    cin>>n;
    VP g(n);
    rep(i,n){
        cin>>x>>y;
        g[i] = {x,y};
    }
    cin>>q;
    rep(i,q){
    	cin>>x>>y;
    	cout<<inPolygon(g,Point(x,y))<<endl;
    }
    return 0;
}
