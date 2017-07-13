#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-9;
#define EQ(n,m) (abs((n)-(m)) < EPS)

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

bool isecSP(Point a1, Point a2, Point b) {
  return !ccw(a1, a2, b);
}

Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

VP crosspointSC(Point a1, Point a2, Point c, double r) {
  VP ps;
  Point ft = proj(a1, a2, c);
  if (r*r < norm(ft-c)) return ps;
  Point dir = sqrt(max(r*r - norm(ft-c), 0.0)) / abs(a2-a1) * (a2-a1);
  if(isecSP(a1,a2,ft+dir)) ps.push_back(ft+dir);
  if (!EQ(r*r, norm(ft-c)) && isecSP(a1,a2,ft-dir))
    ps.push_back(ft-dir);
  return ps;
}

// aからbへの回転角（中心(0,0)）[-pi,+pi]
double angle(Point a,Point b){
    double t = arg(b)-arg(a);
    while(t>+M_PI) t-=2*M_PI;
    while(t<-M_PI) t+=2*M_PI;
    return t;
}

int main(void){
    int n;
    double r,x,y;
    cin>>n>>r;
    VP ps(n);
    rep(i,n){
        cin>>x>>y;
        ps[i] = Point(x,y);
    }

    double area=0;
    rep(i,n){
        Point p=ps[i], q=ps[(i+1)%n];
        VP cp = crosspointSC(p,q,Point(0,0),r);
        if(abs(p)<r && abs(q)<r){
            assert(cp.size()==0);
            area += cross(p,q)/2;
        }
        else if(abs(p)<r && abs(q)>=r){
            assert(cp.size()==1);
            area += cross(p,cp[0])/2;
            area += r*r*angle(cp[0],q)/2;
        }
        else if(abs(p)>=r && abs(q)<r){
            assert(cp.size()==1);
            area += r*r*angle(p,cp[0])/2;
            area += cross(cp[0],q)/2;
        }
        // abs(p)>=r && abs(q)>=r
        else if(cp.size()==2){
            if(abs(p-cp[0])>abs(p-cp[1])) swap(cp[0],cp[1]);
            area += r*r*angle(p,cp[0])/2;
            area += cross(cp[0],cp[1])/2;
            area += r*r*angle(cp[1],q)/2;
        }
        else area += r*r*angle(p,q)/2;
    }
    printf("%.10f\n",area);

    return 0;
}
