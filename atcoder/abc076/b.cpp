#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int N,K,res=1;
    cin>>N>>K;
    rep(i,N){
        if(res*2<res+K)res*=2;
        else res+=K;
    }
    cout<<res<<endl;
    return 0;
}
