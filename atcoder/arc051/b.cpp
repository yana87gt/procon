#include <bits/stdc++.h>
using namespace std;

int f[45]={};

int fib(int n){
    if(n<2)return n;
    else if(f[n])return f[n];
    else return f[n] = fib(n-2)+fib(n-1);
}

int main() {
    int K;
    cin>>K;
    cout<<fib(K+2)<<" "<<fib(K+1)<<endl;
}
