#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ch_edge(CH,i) CH[i],CH[(i+1)%CH.size()]

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

int main(void){
    int n;
    cin>>n;
    VP p(n);
    rep(i,n){
        double x,y;
        cin>>x>>y;
        p[i] = {x,y};
    }

    double s=0;
    rep(i,n) s+=cross(ch_edge(p,i));
    printf("%.1f\n",s/2.0);
    return 0;
}
