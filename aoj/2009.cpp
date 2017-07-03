#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define eps 1e-10
struct Point{double x,y;};
bool comp(Point a,Point b) {return (a.x==b.x ? a.y<b.y : a.x<b.x);}
double dist(Point a,Point b) {return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));}

bool Intersection(Point p1,Point p2,Point p3,Point p4,Point *ret){
    double d = (p2.x-p1.x)*(p4.y-p3.y)-(p2.y-p1.y)*(p4.x-p3.x);
    double u = ((p3.x-p1.x)*(p4.y-p3.y)-(p3.y-p1.y)*(p4.x-p3.x))/d;
    double v = ((p3.x-p1.x)*(p2.y-p1.y)-(p3.y-p1.y)*(p2.x-p1.x))/d;
    if(d==0 || u<=0 || u>=1 || v<=0 || v>=1)return false;
    ret->x = p1.x+u*(p2.x-p1.x);
    ret->y = p1.y+u*(p2.y-p1.y);
    return true;
}

int main(void){
    int n;
    while(cin>>n,n){
        int division=1;
        vector<Point> p1(n);
        vector<Point> p2(n);
        rep(i,n){
            cin>>p1[i].x>>p1[i].y>>p2[i].x>>p2[i].y;
            vector<Point> cross;
            rep(j,i){
                Point ret;
                if(Intersection(p1[i],p2[i],p1[j],p2[j],&ret)){
                    cross.push_back(ret);
                }
            }
            sort(cross.begin(),cross.end(),comp);
            int cnt=1;
            if(cross.size()==0)cnt=0;
            for(int j=0;j+1<cross.size();j++){
                cnt+=(dist(cross[j],cross[j+1])>=eps);
            }
            division += cnt+1;
        }
        cout<<division<<endl;
    }

    return 0;
}
