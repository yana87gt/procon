#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-4;

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

VP convexHull(VP ps) {  // 元の点集合がソートされていいならVP&に
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  VP ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;  // 余計な点も含むなら == -1 とする
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}

int main(void){
    int N;
    while(cin>>N,N){
        vector<string> s(N);
        rep(i,N)cin>>s[i];
        reverse(s.begin(),s.end());

        vector<vector<bool>> inside(N+1,vector<bool>(N+1,true));
        rep(y,N)rep(x,N)if(s[y][x]=='0'){
            rep(dy,2)rep(dx,2){
                inside[y+dy][x+dx] = false;
            }
        }

        VP ps;
        rep(y,N+1)rep(x,N+1)if(inside[y][x]){
            ps.push_back(Point(x,y));
        }
        ps = convexHull(ps);
        reverse(ps.begin()+1,ps.end());
        cout<<ps.size()<<endl;
        for(Point p:ps){
            cout<<p.X<<" "<<p.Y<<endl;
        }
    }
    return 0;
}
