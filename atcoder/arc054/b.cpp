#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;
double P;
double T(double x){return x+P/pow(2.0,x/1.5);}

int main(void){
    double left=0,right=100,mid1,mid2;
    cin>>P;
    while(fabs(T(right)-T(left))>eps){
        mid1=(2.0*left+right)/3.0;
        mid2=(left+2.0*right)/3.0;
        if(T(mid1)<T(mid2))right=mid2;
        else left=mid1;
    }
    printf("%.10f\n",T((left+right)/2.0));
    return 0;
}
