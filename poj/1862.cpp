#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int N;
double w[100];
double func(int n){
    if(n==N-1)return w[n];
    return 2*sqrt(w[n]*func(n+1));
}

int main(void){
    cin>>N;
    rep(i,N)cin>>w[i];
    sort(w,w+N);
    printf("%.3f\n",func(0));
    return 0;
}
