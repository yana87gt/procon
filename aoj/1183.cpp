#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define INF 1e9
const double EPS = 1e-9;
typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

VP crosspointCC(Point a, double ar, Point b, double br){
  double d = abs(b-a);
  if(abs(ar-br)>d || abs(ar+br)<d) return {};
  double t = acos(double((d*d+ar*ar-br*br)/(2*d*ar)));
  Point p1 = a+polar(ar,arg(b-a)+t);
  Point p2 = a+polar(ar,arg(b-a)-t);
  if(abs(p1-p2) < EPS) return {p1};
  return {p1,p2};
}

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
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on ps
  if (norm(b) < norm(c)) return -2;  // a--b--c on ps or a==b
  return 0;                          // a--c--b on ps or a==c or b==c
}

bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

int main(void){
    int n;
    while(cin>>n, n){
        VP c(n);
        vector<double> r(n);
        rep(i,n){
            double x,y;
            cin>>x>>y>>r[i];
            c[i] = {x,y};
        }

        vector<VP> ps(n+1);
        ps[0] = {c[0],c[0]};
        ps[n] = {c[n-1],c[n-1]};
        rep(i,n-1){
            ps[i+1] = crosspointCC(c[i],r[i],c[i+1],r[i+1]);
            assert(ps[i+1].size()==2);
        }

        vector<vector<double>> d((n+1)*2,vector<double>((n+1)*2,INF));
        rep(i,n) for(int j=i+1;j<=n;j++) rep(i2,2) rep(j2,2) {
            bool connect=true;
            for(int k=i+1;k<j;k++) {
                connect &= isecSS(ps[i][i2],ps[j][j2],ps[k][0],ps[k][1]);
            }
            if(connect){
                d[i*2+i2][j*2+j2] = abs(ps[i][i2]-ps[j][j2]);
            }
        }

        rep(k,(n+1)*2) rep(i,(n+1)*2) rep(j,(n+1)*2)
            d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

        printf("%.9f\n",d[0][n*2]);
    }
    return 0;
}
