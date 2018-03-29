#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int w,h,n;
    cin>>w>>h>>n;
    int lx=0,rx=w,ly=0,ry=h;
    rep(i,n){
        int x,y,a;
        cin>>x>>y>>a;
        if(a==1) lx = max(lx,x);
        if(a==2) rx = min(rx,x);
        if(a==3) ly = max(ly,y);
        if(a==4) ry = min(ry,y);
    }
    cout<<((lx>=rx || ly>=ry) ? 0 : (rx-lx)*(ry-ly))<<endl;
    return 0;
}
