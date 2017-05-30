#include<iostream>
#include<stdio.h>
using namespace std;

int main (void){
    int N,K;
    cin >> N; cin >> K;
    printf("%.20f\n",(6.0*K*(N-K+1)-3.0*N-2.0)/N/N/N);
    return 0;
}
