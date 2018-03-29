#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int a,b,c,x,cnt=0;
    cin>>a>>b>>c>>x;
    rep(i,a+1)rep(j,b+1)rep(k,c+1){
        if(i*500+j*100+k*50 == x){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
