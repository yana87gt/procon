#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int N,M,K;
    cin>>N>>M>>K;
    rep(y,M+1)rep(x,N+1){
        if(x*M+y*N-x*y*2==K){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
