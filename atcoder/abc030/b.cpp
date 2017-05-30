#include <stdio.h>
int main(void){
    int n,m;
    scanf("%d %d",&n,&m);
    if(n>=12)n-=12;
    double short_deg=30*n+m/2.0,long_deg=6.0*m;

    double dif_deg=short_deg-long_deg;
    if(dif_deg<0)dif_deg*=-1.0;
    if(dif_deg>180)dif_deg=360.0-dif_deg;

    if(((int)dif_deg)==dif_deg)
        printf("%d\n",(int)dif_deg);
    else
        printf("%.1f\n",dif_deg);

    return 0;
}
