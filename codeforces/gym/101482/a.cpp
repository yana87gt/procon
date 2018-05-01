#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl

typedef complex<double> Point;
typedef vector<Point> VP;
const double EPS = 1e-9;
const double INF = 1e9;
#define X real()
#define Y imag()
#define LE(n,m) ((n) - (m) < EPS)
#define GE(n,m) (EPS > (m) - (n))
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

// 線分と線分
bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// 頂点の順序（sortやmax_elementに必要）
namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}

// 凸包
// 入力1個 -> 空
// 2個以上の全て同じ点 -> 同じもの2つ
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

// 多角形の内部判定
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inPolygon(const VP& ps, Point p) {
  int n = ps.size();
  bool in = false;
  rep (i, n) {
    Point a = ps[i] - p;
    Point b = ps[(i + 1) % n] - p;
    if (EQ(cross(a,b), 0) && LE(dot(a,b), 0)) return 2;
    if (a.Y > b.Y) swap(a,b);
    if ((a.Y*b.Y < 0 || (a.Y*b.Y < EPS && b.Y > EPS)) && LE(cross(a, b), 0)) in = !in;
  }
  return in;
}


int main(void){
    int n,m;
    cin>>n;
    VP inner(n);
    rep(i,n){
        double x,y;
        cin>>x>>y;
        inner[i] = {x,y};
    }
    cin>>m;
    VP outer(m);
    rep(i,m){
        double x,y;
        cin>>x>>y;
        outer[i] = {x,y};
    }

    VP ps;
    rep(i,n) ps.push_back(inner[i]);
    rep(i,m) ps.push_back(outer[i]);
    int N = ps.size();
    double d[N][N];
    rep(i,N)rep(j,N) d[i][j] = (i==j) ? 0 : INF;
    
    // 全点集合ps間の線分(i,j)について直線で移動可能か
    rep(i,N)rep(j,i){
        bool ok = true;

        // 線分(i,j) と innerの各辺 の交差判定
        rep(k,n){
            // ps[i]またはps[j] が 辺の端点 ならスルー
            if( EQ(inner[k],ps[i]) || EQ(inner[k],ps[j]) || 
                EQ(inner[(k+1)%n],ps[i]) || EQ(inner[(k+1)%n],ps[j])){
                continue;
            }

            if(isecSS(ps[i],ps[j],inner[k],inner[(k+1)%n])){
                ok = false;
                break;
            }

        }

        // 線分(i,j) と outerの各辺 の交差判定
        rep(k,m){
            // ps[i]またはps[j] が 辺の端点 ならスルー
            if( EQ(outer[k],ps[i]) || EQ(outer[k],ps[j]) || 
                EQ(outer[(k+1)%m],ps[i]) || EQ(outer[(k+1)%m],ps[j])){
                continue;
            }

            if(isecSS(ps[i],ps[j],outer[k],outer[(k+1)%m])){
                ok = false;
                break;
            }
        }

        // 線分(i,j)の中点 が innerの内部 または outerの外部 にあるか
        if( inPolygon(inner, (ps[i]+ps[j])*0.5) == 1 ||
            inPolygon(outer, (ps[i]+ps[j])*0.5) == 0){
            ok = false;
        }

        if(ok){
            double dist = abs(ps[i]-ps[j]);
            d[i][j] = dist;
            d[j][i] = dist;
        }
    }

    // ワーシャルフロイド
    rep(k,N)rep(i,N)rep(j,N){
        if( d[i][j] > d[i][k] + d[k][j]){
            d[i][j] = d[i][k] + d[k][j];
        }
    }

    // innerの凸包をとった頂点は必ずその順に訪れるので
    // その凸包の各隣接頂点間の最短距離の総和が答え
    VP ch = convexHull(inner);
    int C = ch.size();
    vector<int> id(C);
    rep(k,C)rep(i,N){
        if(EQ(ch[k], ps[i])){
            id[k] = i;
        }
    }

    double sum = 0;
    rep(k,C){
        sum += d[id[k]][id[(k+1)%C]];
    }
    printf("%.10f\n", sum);

    return 0;
}
