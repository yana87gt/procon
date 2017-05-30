#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int N;
    while(cin>>N,N){
        int T,minT=50,maxT=-50;
        rep(i,N){
            cin>>T;
            minT=min(T,minT);
            maxT=max(T,maxT);
        }
        cout<<maxT-minT<<endl;
    }
    return 0;
}
