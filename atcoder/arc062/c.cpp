#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long N,T,A,k,t=1,a=1;
    cin>>N;
    while(N--){
        cin>>T>>A;
        k=max((t-1)/T+1,(a-1)/A+1);
        t=T*k;
        a=A*k;
    }
    cout<<t+a<<endl;
    return 0;
}
