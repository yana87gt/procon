#include <bits/stdc++.h>
using namespace std;
double P;
double T(double x){return x+P/pow(2.0,x/1.5);}
int main(void){
    cin>>P;
    double x=-1.5*log(1.5/P/log(2))/log(2);
    printf("%.10f\n",T(max(x,0.0)));
    return 0;
}
