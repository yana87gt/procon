#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define eps 1e-9

struct Point{double x,y; bool high;};
bool comp(Point a,Point b) {return (a.x==b.x ? a.y<b.y : a.x<b.x);}

Point* Intersection(Point p1,Point p2,Point p3,Point p4,bool high){
    double d = (p2.x-p1.x)*(p4.y-p3.y)-(p2.y-p1.y)*(p4.x-p3.x);
    double u = ((p3.x-p1.x)*(p4.y-p3.y)-(p3.y-p1.y)*(p4.x-p3.x))/d;
    double v = ((p3.x-p1.x)*(p2.y-p1.y)-(p3.y-p1.y)*(p2.x-p1.x))/d;
    if(fabs(d)<=eps || u<0 || u>1 || v<0 || v>1) return NULL;
    return new Point{p1.x+u*(p2.x-p1.x), p1.y+u*(p2.y-p1.y), high};
}

int main(void){
    int N,n,o,l;
    cin>>N;
    while(N--){
        Point a,b;
        vector<Point> cross;
        cin>>a.x>>a.y>>b.x>>b.y>>n;
        rep(i,n){
            Point s,t;
            cin>>s.x>>s.y>>t.x>>t.y>>o>>l;
            Point *ret = Intersection(a,b,s,t,o==l);
            if(ret)cross.push_back(*ret);
        }

        sort(cross.begin(),cross.end(),comp);
        int cnt=0;
        rep(i,(int)cross.size()-1){
            cnt += (cross[i].high!=cross[i+1].high);
        }
        cout<<cnt<<endl;
    }

    return 0;
}
