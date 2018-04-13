#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
const double EPS = 1e-6;
const double PI = acos(-1);
#define EQ(n,m) (abs((n)-(m)) < EPS)

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d:\n",_+1);
        double A;
        cin>>A;
        if(A <= sqrt(2.0)){
            double l=0, r=PI/4, t, x, y;
            rep(i,100){
                t = (l+r)/2;
                x = 0.5*cos(t);
                y = 0.5*sin(t);
                if((x+y)*2 < A) l = t;
                else r = t;
            }
            assert(EQ((x+y)*2, A));
            printf("%.10f %.10f 0\n", x, y);
            printf("%.10f %.10f 0\n",-y, x);
            printf("0 0 0.5\n");
        }else{
            double l=0, r=asin(1/sqrt(3)), t, area;
            rep(i,100){
                t = (l+r)/2;
                area = cos(t)*sqrt(2)+sin(t);
                if(area < A) l = t;
                else r = t;
            }
            assert(EQ(area, A));
            double d = sqrt(2)/4;
            printf("0 %.10f %.10f\n", 0.5*sin(t), 0.5*cos(t));
            printf("%.10f %.10f %.10f\n", d, d*cos(t), -d*sin(t));
            printf("%.10f %.10f %.10f\n",-d, d*cos(t), -d*sin(t));
        }
        
    }
    return 0;
}
