#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double INF = 1e9;

bool compX(const Point a, const Point b) {
    return a.X<b.X;
}

bool compY(const Point a, const Point b) {
    return a.Y<b.Y;
}

double closestPair(VP &a,int l,int r) {
    if(r-l<=1) return INF;
    int m = (l+r)/2;
    double x = a[m].X;
    double d = min(closestPair(a,l,m),closestPair(a,m,r));
    inplace_merge(a.begin()+l,a.begin()+m,a.begin()+r,compY);
    
    VP b;
    for(int i=l;i<r;i++){
        if(abs(a[i].X - x)>=d)continue;
        for(int j=b.size()-1;j>=0;j--){
            if((a[i]-b[j]).Y>=d)break;
            d = min(d,abs(a[i]-b[j]));
        }
        b.push_back(a[i]);
    }
    return d;
}

double closestPair(VP ps){
    sort(ps.begin(),ps.end(),compX);
    return closestPair(ps,0,ps.size());
}

int main(void){
    int n;
    cin>>n;
    VP ps(n);
    rep(i,n){
        double x,y;
        cin>>x>>y;
        ps[i] = Point(x,y);
    }
    printf("%.9f\n",closestPair(ps));
    return 0;
}
