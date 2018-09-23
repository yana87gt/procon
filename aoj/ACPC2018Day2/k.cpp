#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

typedef complex<double> Point;
typedef vector<Point> VP;
const double EPS = 1e-9; // 許容誤差^2
const double INF = 1e9;
const double PI = acos(-1.0);
#define X real()
#define Y imag()
#define LE(n,m) ((n) - (m) < EPS)
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
    if (cross(b,c) > +EPS) return +1;  // counter clockwise
    if (cross(b,c) < -EPS) return -1;  // clockwise
    if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
    if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
    return 0;                          // a--c--b on line or a==c or b==c
}

// 直線と線分
bool isecLS(Point a1, Point a2, Point b1, Point b2) {
    return cross(a2-a1, b1-a1) * 
           cross(a2-a1, b2-a1) < EPS;
}

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
    double d1 = cross(b2-b1, b1-a1);
    double d2 = cross(b2-b1, a2-a1);
    if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
    assert(!EQ(d2, 0)); // 交点がない
    return a1 + d1/d2 * (a2-a1);
}

// 2円の交点
VP crosspointCC(Point a, double ar, Point b, double br) {
    VP ps;
    Point ab = b-a;
    double d = abs(ab);
    double crL = (norm(ab) + ar*ar - br*br) / (2*d);
    if (EQ(d, 0) || ar < abs(crL)) return ps;

    Point abN = ab * Point(0, sqrt(ar*ar - crL*crL) / d);
    Point cp = a + crL/d * ab;
    ps.push_back(cp + abN);
    if (!EQ(norm(abN), 0)) ps.push_back(cp - abN);
    return ps;
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

bool inCircle(Point p, Point c, double r){
    return abs(p-c) <= r;
}

int n,m;
// ps: n個の頂点
// cs: m個の中心
bool check(double r, VP &ps, VP &cs){
    // 全頂点が1つ以上の円に含まれている
    rep(i,n){
        bool ok = false;
        rep(j,m){
            if(inCircle(ps[i], cs[j], r)){
                ok = true;
            }
        }
        if(!ok) return false;
    }

    // 2つの中心の垂直二等分線
    rep(i,m)rep(j,i){
        Point mid = (cs[i]+cs[j])/2.0;
        double d = abs(cs[i]-mid) + 1000.0;
        VP cps = crosspointCC(cs[i],d, cs[j],d);
        rep(k,n){
            if(isecLS(cps[0],cps[1], ps[k],ps[(k+1)%n])){
                Point p = crosspointLL(cps[0],cps[1], ps[k],ps[(k+1)%n]);
                bool ok = false;
                rep(l,m){
                    if(inCircle(p,cs[l],r)) ok = true;
                }
                if(!ok) return false;
            }
        }
    }

    // 2つの円の交点が凸内なら、他の円の中に入っていたい
    rep(i,m)rep(j,i){
        VP cps = crosspointCC(cs[i],r, cs[j],r);
        for(auto p : cps)if(inPolygon(ps, p)){
            bool ok = false;
            rep(k,m)if(k!=i && k!=j){
                if(inCircle(p, cs[k], r)){
                    ok = true;
                }
            }
            if(!ok) return false;
        }
    }

    return true;
}

int main(void){
    cin>>n;
    VP ps(n);
    rep(i,n){
        double x,y;
        cin>>x>>y;
        ps[i] = Point(x,y);
    }
    cin>>m;
    VP cs(m);
    rep(i,m){
        double x,y;
        cin>>x>>y;
        cs[i] = Point(x,y);
    }
    double l = 0, r = 1000000;
    rep(loop,50){
        double radius = (l+r)/2;
        if(check(radius, ps, cs)){
            r = radius;
        }else{
            l = radius;
        }
    }
    printf("%.10f\n", r);
    return 0;
}
