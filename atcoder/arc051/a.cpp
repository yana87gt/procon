#include <iostream>
using namespace std;

int x1,y1,r;
bool inCircle(int x,int y){
    return (x-x1)*(x-x1)+(y-y1)*(y-y1)<=r*r;
}

int main(void){
    int x2,y2,x3,y3;
    cin>>x1>>y1>>r>>x2>>y2>>x3>>y3;

    if((x2<=x1-r) && (x1+r<=x3) && (y2<=y1-r) && (y1+r<=y3))cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    if(inCircle(x2,y2) && inCircle(x2,y3) && inCircle(x3,y2) && inCircle(x3,y3))cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    return 0;
}
