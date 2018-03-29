#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-9;
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

int ccw(Point a, Point b, Point c) {
    b -= a;  c -= a;
    if (cross(b,c) >  EPS) return +1;  // counter clockwise
    if (cross(b,c) < -EPS) return -1;  // clockwise
    if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
    if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
    return 0;                          // a--c--b on line or a==c or b==c
}

// 線分と線分
bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

int main(void){
    int n;
    cin>>n;
    VP p(2*n);
    vector<vector<int>> edge;
    rep(i,n){
        double x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        p[i*2]   = Point(x1,y1);
        p[i*2+1] = Point(x2,y2);
        edge.push_back({i*2+1});
        edge.push_back({i*2});
    }

    rep(i,n)rep(j,i){
        VP tp = {p[i*2],p[i*2+1],p[j*2],p[j*2+1]};
        if(isecSS(p[i*2],p[i*2+1],p[j*2],p[j*2+1])){
            Point cp = crosspointLL(p[i*2],p[i*2+1],p[j*2],p[j*2+1]);
            int newid = p.size();
            p.push_back(cp);
            int id[4] = {i*2,i*2+1,j*2,j*2+1};
            edge.push_back({});
            rep(k,4) if(!EQ(p[newid],p[id[k]])){
                edge[id[k]].push_back(newid);
                edge[newid].push_back(id[k]);
            }
        }
    }


    return 0;
}
