#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int K,S;
    cin>>K>>S;
    int cnt = 0;
    rep(x,K+1)rep(y,K+1){
        int z = S-y-x;
        if(z>=0 && z<=K) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
