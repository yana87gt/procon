#include <bits/stdc++.h>
using namespace std;
int main(void){
    double W,H,w,h,x,y;
    cin>>W>>H>>w>>h>>x>>y;
    printf("%.10f\n",(y-h/2 + min(y+h/2, H/2)) / (x-w/2 + min(x+w/2, W/2)));
    return 0;
}
