#include <vector>
#include <cstdio>
#include <algorithm>
#include <complex>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) a.begin(),a.end()

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

namespace std {
    bool operator<(const Point a, const Point b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

Point center(Point p,double d){
    return {p.X + sqrt(d*d-p.Y*p.Y),0};
}

int solve(int n,double d){
    VP ps(n);
    rep(i,n){
        double x,y;
        scanf("%lf%lf",&x,&y);
        ps[i] = {x,y};
    }
    sort(all(ps));

    int res=0;
    Point c = Point(-1e9,0);
    rep(i,n){
        if(d<ps[i].Y) return -1;
        if(abs(ps[i]-c) > d){
            if(c.X<ps[i].X)res++;
            c = center(ps[i],d);
        }
    }
    return res;
}


int main(void){
    int n,ds=0;
    double d;
    while(scanf("%d %lf",&n,&d),n){
        printf("Case %d: %d\n",++ds,solve(n,d));
    }
    return 0;
}
