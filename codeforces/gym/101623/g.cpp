#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<int(n);i++)

typedef complex<double> Point;
typedef vector<Point> VP;
const double EPS = 1e-9;
#define X real()
#define Y imag()

double dot(Point a, Point b){
    return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b){
    return a.X*b.Y - a.Y*b.X;
}

int ccw(Point a, Point b, Point c){
    b-=a; c-=a;
    if(cross(b,c) >  EPS) return +1;
    if(cross(b,c) < -EPS) return -1;
    if(dot(b,c)   < -EPS) return +2;
    if(norm(b) < norm(c)) return -2;
    return 0; 
}

// in 1, on 2, out 0
int inConvex(Point p, const VP& ps){
    int n = ps.size();
    int dir = ccw(ps[0],ps[1],p);
    rep(i,n){
        int ccwc = ccw(ps[i],ps[(i+1)%n],p);
        if (!ccwc) return 2;
        if (ccwc != dir) return 0;
    }
    return 1;
}

double area(const VP ps){
    double a = 0;
    rep(i,ps.size()){
        a += cross(ps[i],ps[(i+1)%ps.size()]);
    }
    return a/2;
}

VP make_poly(int k,double len){
    VP res;
    rep(i,k){
        res.push_back(polar(len,2*acos(-1)*i/k));
    }
    return res;
}


int main(){
    int n;
    cin>>n;
    VP ps(n);
    rep(i,n){
        double x,y;
        cin>>x>>y;
        ps[i] = Point(x,y);
    }
    
    pair<double,int> res;
    for(int k = 3; k <= 8; k++){
        // inPoly
        double l=0, r=1e7;
        rep(loop,100){
            double len =(l+r)/2;
            VP poly = make_poly(k,len);
            bool ok = true;
            rep(i,n){
                if(inConvex(ps[i],poly)==1) {
                    ok = false;
                    break;
                }
            }
            
            if(ok) l=len;
            else r=len;      
        }
        double in_area = area(make_poly(k,l));

        // outPoly
        l=0; r=1e7;
        rep(loop,100){
            double len = (l+r)/2;
            VP poly = make_poly(k,len);
            bool ok = true;
            rep(i,n){
                if(inConvex(ps[i],poly)==0) {
                    ok = false;
                    break;
                }
            }
            if(ok) r=len;
            else l=len;      
        }
        double out_area = area(make_poly(k,r));
        res = max(res,{in_area/out_area,k});
    }
    
    printf("%d %.10f\n",res.second,res.first);
    return 0;
}