#include <iostream>
#include <algorithm>
#include <stdio.h>

#define M_PI 3.141592653589793238
using namespace std;

int main(void){
    int a[3]={};
    int max,min;
    cin>>a[0]>>a[1]>>a[2];

    max = a[0]+a[1]+a[2];
    sort(a,a+3);
    if(a[0]+a[1]<a[2])min = a[2]-a[1]-a[0];
    else min = 0;
    printf("%.20f\n",(max*max - min*min)*M_PI);

    return 0;
}
