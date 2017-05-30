#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int N;
    int x[1000]={},y[1000]={},c[1000]={};
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> x[i] >> y[i] >> c[i];
    }
 
    double mid,ng=0,ok=1e10;
    while(ok-ng>1e-7)
    {
        mid = (ok+ng)/2.0;
        double L=1e5,R=-1e5,U=-1e5,D=1e5;
        for(int i=0;i<N;i++)
        {
            L = min(L,x[i]+mid/c[i]);
            R = max(R,x[i]-mid/c[i]);
            D = min(D,y[i]+mid/c[i]);
            U = max(U,y[i]-mid/c[i]);
        }
        if(L<=R || D<=U)ng=mid;
        else ok=mid;
    }
 
    printf("%.20f\n",ok);
}