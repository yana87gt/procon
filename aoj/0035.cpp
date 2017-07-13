#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

#define debug(x) cout<<#x<<": "<<x<<endl

double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

bool isConvex(VP ps) {
  int n = ps.size();
  vector<bool> ccw(n);
  rep(i,n) ccw[i] = cross(ps[(i+1)%n]-ps[i], ps[(i+2)%n]-ps[i])>0;
  rep(i,n-1) if(ccw[i]!=ccw[i+1]) return false;
  return true;
}

int main(void){
    double xa,ya,xb,yb,xc,yc,xd,yd;
    while(scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
        &xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd)!=EOF){
        if(isConvex({{xa,ya},{xb,yb},{xc,yc},{xd,yd}})){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;
    }
    return 0;
}
