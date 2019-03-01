#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int c[2],k;
    cin>>c[0]>>c[1]>>k;
    rep(i,k){
        if(c[i%2]&1){
            c[i%2]--;
        }
        c[(i+1)%2] += c[i%2]/2;
        c[i%2]/=2;
    }
    cout<<c[0]<<" "<<c[1]<<endl;

    return 0;
}
