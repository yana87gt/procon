#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
struct Point{double x,y;};
double dist(Point a,Point b) {return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));}

int main(void){
    int N;
    while(cin>>N,N){
        vector<Point> p(N);
        int maxcnt=1;
        rep(i,N)cin>>p[i].x>>p[i].y;
        rep(i,N){
            for(int j=i+1;j<N;j++){
                double d = dist(p[i],p[j]);
                if(d>2.0)continue;
                int sign[]={-1,1};
                rep(s,2){
                    Point C;
                    C.x = p[i].x + cos(atan2(p[j].y-p[i].y,p[j].x-p[i].x) + sign[s]*acos(d/2.0));
                    C.y = p[i].y + sin(atan2(p[j].y-p[i].y,p[j].x-p[i].x) + sign[s]*acos(d/2.0));
                    int cnt=0;
                    rep(k,N) cnt += (pow(C.x-p[k].x,2) + pow(C.y-p[k].y,2) <= 1.0001);
                    if(maxcnt<cnt)maxcnt=cnt;
                }
            }
        }
        cout<<maxcnt<<endl;
    }

    return 0;
}
