#include <bits/stdc++.h>
using namespace std;
int count(int p,int q,int n,int i,int max,int acc){
    if(p==0) return 1;
    if(n==0) return 0;
    int result = 0;
    for(;i*acc<=max;i++){
        result += count(p*i-q,i*q,n-1,i,max,i*acc);
    }
    return result;
}
 
int main(void){
    int p,q,a,n;
    while(cin>>p>>q>>a>>n,p|q|a|n){
        cout<<count(p,q,n,1,a,1)<<endl;
    }

    return 0;
}