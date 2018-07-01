#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<int(n);++i)
#define all(a) a.begin(),a.end()

typedef complex<double> Point;
typedef vector<Point> VP;
const double INF = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
#define X real()
#define Y imag()


double dot(Point a, Point b){
    return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b){
    return a.X*b.Y - a.Y*b.X;
}

int ccw(Point a, Point b, Point c){
    b -= a; c -= a;
    if(cross(b,c) > +EPS) return +1;
    if(cross(b,c) < -EPS) return -1;
    if(dot(b,c)   < -EPS) return +2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}


bool isecSS(Point a1,Point a2,Point b1,Point b2){
    return ccw(a1,a2,b1)*ccw(a1,a2,b2) <= 0 &&
           ccw(b1,b2,a1)*ccw(b1,b2,a2) <= 0;
}

bool isecSP(Point a1,Point a2,Point b){
    return !ccw(a1,a2,b);
}

Point proj(Point a1, Point a2, Point p){
    return a1 + dot(a2-a1, p-a1)/norm(a2-a1)*(a2-a1);
}

double distSP(Point a1, Point a2, Point p){
    Point r = proj(a1,a2,p);
    if(isecSP(a1,a2,r)) return abs(r-p);
    return min(abs(a1-p),abs(a2-p));
}


double distSS(Point a1,Point a2,Point b1,Point b2){
    if(isecSS(a1,a2,b1,b2)) return 0;
    return min({
        distSP(a1,a2,b1),
        distSP(a1,a2,b2),
        distSP(b1,b2,a1),
        distSP(b1,b2,a2)});
}

VP make_star(double x,double y,double a,double r){
    VP s(5);
    rep(i,5){
        s[i] = Point(x,y) + polar(r, (90+a+144*i)*PI/180.0);
    }
    return s;
}

double dist_star(VP s1, VP s2){
    double res = INF;
    rep(i,5)rep(j,5){
        double dist = distSS(s1[i],s1[(i+1)%5], s2[j],s2[(j+1)%5]);
        res = min(res,dist);
    }
    return res;
}

int main(){
    int N,M,L;
    while(cin>>N>>M>>L, N|M|L){
        vector<VP> st(N);
        rep(i,N){
            double x,y,a,r;
            cin>>x>>y>>a>>r;
            st[i] = make_star(x,y,a,r);
        }
        vector<vector<double>> d(N, vector<double>(N, INF));
        rep(i,N) d[i][i] = 0;
        rep(i,N)rep(j,i){
            double dist = dist_star(st[i],st[j]);
            d[i][j] = dist;
            d[j][i] = dist;
        }
        rep(k,N)rep(i,N)rep(j,N) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        printf("%.20f\n",d[M-1][L-1]);
    }
}