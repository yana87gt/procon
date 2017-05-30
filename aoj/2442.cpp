#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
struct Point{double x,y;};

int main(void){
    int N;
    bool NA = false;
    cin>>N;
    vector<Point> p(N);
    rep(i,N)cin>>p[i].x>>p[i].y;
    NA = N&1;
    Point G = {(p[0].x+p[N/2].x)/2.0 , (p[0].y+p[N/2].y)/2.0};
    rep(i,N/2) NA |= ((p[i].x+p[i+N/2].x)/2.0!=G.x || (p[i].y+p[i+N/2].y)/2.0!=G.y);
    if(NA)cout<<"NA"<<endl;
    else printf("%.5f %.5f\n",G.x,G.y);

    return 0;
}
