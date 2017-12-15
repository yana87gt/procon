#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;
#define double long double

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-9;

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

Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

double distSP(Point a1, Point a2, Point p) {
  Point r = proj(a1, a2, p);
  if (!ccw(a1, a2, r)) return abs(r-p);
  return min(abs(a1-p), abs(a2-p));
}

void solve(){
    int n;
    double r = 3999;
    cin>>n;
    VP p(n);
    rep(i,n){
        double x,y;
        cin>>x>>y;
        p[i] = Point(x,y);
    }
    VP cs;
    rep(i,n){
        Point a = p[i], b = p[(i+1)%n], c = p[(i+2)%n];
        if(ccw(a,b,c) == -1){
            double t1 = arg(a-b);
            double t2 = arg(c-b);
            Point circle = b + polar(r/abs(sin((t2-t1)/2)) + 1e-2,(t1+t2)/2);
            bool ok = true;
            rep(j,n){
                Point d = p[j], e = p[(j+1)%n];
                if(distSP(d,e,circle)+1 < r){
                    ok = false;
                    break;
                }
            }
            if(ok)cs.push_back(circle);
        }
    }
    int m = cs.size();
    rep(i,m)rep(j,i){
        if(abs(cs[i]-cs[j]) > 2*r+1){
            printf("%.10Lf %.10Lf\n",cs[i].X,cs[i].Y);
            printf("%.10Lf %.10Lf\n",cs[j].X,cs[j].Y);
            return;
        }
    }
    cout<<"impossible"<<endl;
}

int main(void){
    solve();
    return 0;
}
