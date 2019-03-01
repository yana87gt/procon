#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-9;
const double PI = acos(-1.0);
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define ps_edge(PS,i) PS[i],PS[(i+1)%PS.size()]

namespace std {
    bool operator<(const Point a, const Point b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

double dot(Point a, Point b) {
    return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b) {
    return a.X*b.Y - a.Y*b.X;
}

int inPolygon(Point p, const VP& ps) {
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
    int n;
    cin>>n;
    VP ps = {Point(n*0.5,0),Point(n,n*0.5),Point(n*0.5,n),Point(0,n*0.5)};
    int cnt = 0;
    rep(y,n)rep(x,n){
        if( inPolygon(Point(y,x), ps) && 
            inPolygon(Point(y+1,x), ps) &&
            inPolygon(Point(y,x+1), ps) &&
            inPolygon(Point(y+1,x+1), ps)){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
