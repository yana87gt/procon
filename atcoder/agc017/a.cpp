#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

ll C[60][60]={};
ll com(int n, int r){
    if(C[n][r]!=0) return C[n][r];
    else if(n==r || r==0) return C[n][r]=1;
    else if(r==1 || r==n-1) return C[n][r]=n;
    else return  C[n][r] = C[n][n-r] = com(n-1,r-1) + com(n-1,r);
}

int main(void){
    int N,P,A;
    ll even=0,odd;
    cin>>N>>P;
    rep(i,N){
        cin>>A;
        if(A%2==0)even++;
    }
    ll oddsum=0,evensum=0;
    odd = N-even;
    if(P==0){
        for(int i=0;i*2<=odd;i++){
            oddsum += com(odd,i*2);
        }
        for(int i=0;i<=even;i++){
            evensum += com(even,i);
        }
    }else{
        for(int i=0;i*2+1<=odd;i++){
            oddsum += com(odd,i*2+1);
        }
        for(int i=0;i<=even;i++){
            evensum += com(even,i);
        }
    }
    cout<<evensum*oddsum<<endl;

    return 0;
}
