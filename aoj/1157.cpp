#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e14

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-8;
const double PI = acos(-1);

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

bool isecSS(Point a1, Point a2, Point b1, Point b2) {
    return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
           ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

Point proj(Point a1, Point a2, Point p) {
    return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

double distSP(Point a1, Point a2, Point p) {
    Point r = proj(a1, a2, p);
    if (isecSP(a1, a2, r)) return abs(r-p);
    return min(abs(a1-p), abs(a2-p));
}

double distSS(Point a1, Point a2, Point b1, Point b2) {
    if (isecSS(a1, a2, b1, b2)) return 0;
    return min({
        distSP(a1, a2, b1),
        distSP(a1, a2, b2),
        distSP(b1, b2, a1),
        distSP(b1, b2, a2)});
}

bool inPolygon(Point p,VP& ps){
    int n = ps.size();
    double sumAngle=0;
    rep(i,n){
        double t = arg(ps[(i+1)%n]-p)-arg(ps[i]-p);
        while(t > +PI) t-=2*PI;
        while(t < -PI) t+=2*PI;
        sumAngle += t;
    }
    return (abs(sumAngle) > 0.1);
}

int main(void){
    int n;
    while(cin>>n, n){
        double sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        Point s(sx,sy);
        Point e(ex,ey);
        vector<double> d(n,INF), h(n);
        bool ng = false;
        rep(i,n){
            double x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2>>h[i];
            VP p = {{x1,y1},{x2,y1},{x2,y2},{x1,y2}};
            if(inPolygon(s,p) || inPolygon(e,p)){
                ng = true;
            }
            rep(j,4){
                d[i] = min(d[i],distSS(s,e,p[j],p[(j+1)%4]));
            }
        }
        if(ng){
            cout<<"0.0000"<<endl;
            continue;
        }

        double l = 0, r = 1000;
        rep(loop,100){
            double R = (l+r)/2;
            bool ok = true;
            rep(i,n){
                if(sqrt(pow(max(R-h[i],0.0),2) + pow(d[i],2)) < R){
                    ok = false;
                }
            }
            if(ok) l = R;
            else   r = R;
        }
        printf("%.4f\n",l);
    }
    return 0;
}
