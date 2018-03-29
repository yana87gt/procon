#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-9;
const double PI = acos(-1);
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

Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

Point sym(Point base,Point p){
    return base*2.0 - p;
}

Point face(string XY, int deg, double len){
    double theta = deg*PI/180.0;
    VP a(3),pivot(3),g(3);
    rep(i,3) a[i] = polar(2/sqrt(3),2*PI*i/3);
    rep(i,3) pivot[i] = polar(1/sqrt(3),2*PI*i/3 + PI);
    rep(i,3) g[i] = polar(1/sqrt(3),2*PI*i/3);
    Point s,t;
    if(XY == "BC"){
        s = a[2];
        t = s + polar(len,arg(a[1]-a[2])-theta);
    }
    if(XY == "CD"){
        s = a[0];
        t = s + polar(len,arg(a[2]-a[0])-theta);
    }
    if(XY == "DB"){
        s = a[1];
        t = s + polar(len,arg(a[0]-a[1])-theta);
    }

    bool finish = false;
    while(!finish){
        finish = true;
        rep(i,3){
            if(!isecSS(s,t,a[i],a[(i+1)%3])) continue;
            Point cp = crosspointLL(s,t,a[i],a[(i+1)%3]);
            if(!EQ(cp,s)){
                Point base = pivot[(i+2)%3];
                s = sym(base,cp);
                t = sym(base,t);
                finish = false;
                break;
            }
        }
    }
    Point closest(0,0);
    rep(i,3) if(abs(closest-t) > abs(g[i]-t)){
        closest = g[i];
    }
    return closest;
}

int main(void){
    string XY1,XY2;
    int d1,d2,l1,l2;
    cin>>XY1>>d1>>l1;
    cin>>XY2>>d2>>l2;
    if(EQ(face(XY1,d1,l1),face(XY2,d2,l2))){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
