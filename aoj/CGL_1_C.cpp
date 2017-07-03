#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef complex<double> Point;
#define X real()
#define Y imag()
const double EPS = 1e-9;

double dot(Point a, Point b) {
    return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b) {
    return a.X*b.Y - a.Y*b.X;
}

string ccw(Point a, Point b, Point c) {
    b -= a;  c -= a;
    if (cross(b,c) >  EPS) return "COUNTER_CLOCKWISE";
    if (cross(b,c) < -EPS) return "CLOCKWISE";
    if (dot(b,c)   < -EPS) return "ONLINE_BACK";  // c--a--b on line
    if (norm(b) < norm(c)) return "ONLINE_FRONT"; // a--b--c on line or a==b
                           return "ON_SEGMENT";   // a--c--b on line or a==c or b==c
}

int main(void){
    double x1,y1,x2,y2,x,y;
    int q;
    cin>>x1>>y1>>x2>>y2>>q;
    rep(i,q){
        cin>>x>>y;
        cout<<ccw({x1,y1},{x2,y2},{x,y})<<endl;
    }
    return 0;
}
