#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<int(n); ++i)
typedef complex<double> Point;
#define X real()
#define Y imag()

double dot(Point a,Point b){ return a.X*b.X+a.Y*b.Y; }
double cross(Point a,Point b){ return a.X*b.Y-a.Y*b.X; }
Point proj(Point a1,Point a2,Point p){
    return a1 + dot(a2-a1,p-a1)/norm(a2-a1) * (a2-a1);
}

namespace std {
    bool operator<(const Point a,const Point b){
        return a.X!=b.X ? a.X<b.X : a.Y<b.Y;
    }
}

vector<Point> p;
int N;

// 平行な2つの直線L1,L2があり、L1に点aと点b、L2に点cがある
// L1とL2の間に全ての点があり、その幅がside以下であるか調べる
bool check(Point a,Point b,Point c,double side){
    Point maxP = max(a,b), minP = min(a,b);
    rep(k,N){
        if(cross(b-a,p[k]-a)<0) return false;
        if(cross(p[k]-c,b-a)<0) return false;
        Point pj = proj(a,b,p[k]);
        maxP = max(maxP,pj);
        minP = min(minP,pj);
    }
    return abs(maxP-minP)<=side;
}

bool solve(){
    double H,W,R;
    cin>>N>>H>>W>>R;
    rep(i,N) {
        double x,y;
        cin>>x>>y;
        p.push_back(Point(x,y));
    }
    H -= R*2, W -= R*2;
    if(min(H,W)<0) return false;

    double dmax = 0;
    rep(i,N)rep(j,i){
        double d = abs(p[j]-p[i]);
        double t = arg(p[j]-p[i]);
        if(sqrt(H*H+W*W)<d) return false;
        dmax = max(dmax,d);

        // 長方形の対辺にそれぞれp[i]とp[j]がある
        if(H<=d){
            Point q1 = p[j] + polar(H,t+acos(H/d)-M_PI);
            Point q2 = p[j] + polar(H,t-acos(H/d)-M_PI);
            if(check(p[i],q1,p[j],W)) return true;
            if(check(q2,p[i],p[j],W)) return true;
        }
        if(W<=d){
            Point q3 = p[j] + polar(W,t+acos(W/d)-M_PI);
            Point q4 = p[j] + polar(W,t-acos(W/d)-M_PI);
            if(check(p[i],q3,p[j],H)) return true;
            if(check(q4,p[i],p[j],H)) return true;
        }
    }

    return dmax<=min(H,W);
}
 
int main(){
    cout<<(solve() ? "Yes" : "No")<<endl;
}