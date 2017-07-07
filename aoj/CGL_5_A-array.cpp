#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double INF = 1e9;

bool compX(const Point a, const Point b) {
    return (a.X!=b.X ? a.X<b.X : a.Y<b.Y);
}

bool compY(const Point a, const Point b) {
    return a.Y<b.Y;
}

double closestPair(Point *a,int n) {
    if(n<=1) return INF;
    int m = n/2;
    double x = a[m].X;
    double d = min(closestPair(a,m),closestPair(a+m,n-m));
    inplace_merge(a,a+m,a+n,compY);
    
    VP b;
    rep(i,n){
        if(abs(a[i].X - x)>=d)continue;
        for(int j=b.size()-1;j>=0;j--){
            if((a[i]-b[j]).Y>=d)break;
            d = min(d,abs(a[i]-b[j]));
        }
        b.push_back(a[i]);
    }
    return d;
}

int main(void){
    int n;
    cin>>n;
    Point ps[n];
    rep(i,n){
        double x,y;
        cin>>x>>y;
        ps[i] = Point(x,y);
    }
    sort(ps,ps+n,compX);
    printf("%.9f\n",closestPair(ps,n));
    return 0;
}
