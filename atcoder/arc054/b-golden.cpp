#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;
double P;
double T(double x){return x+P/pow(2.0,x/1.5);}

int main(void){
    double left=0,right=100;
    double mid1=right*(3-sqrt(5))/2;
    double mid2=right-mid1;
    cin>>P;
    while(fabs(T(right)-T(left))>eps){
        if(T(mid1)<T(mid2)){
            right=mid2;
            mid2=mid1;
            mid1=left+right-mid2;
        }else{
            left=mid1;
            mid1=mid2;
            mid2=right+left-mid1;
        }
    }
    printf("%.10f\n",T((left+right)/2.0));
    return 0;
}
