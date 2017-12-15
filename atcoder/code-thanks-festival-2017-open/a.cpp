#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int res=0,t;
    rep(i,8){
        cin>>t;
        res = max(res,t);
    }
    cout<<res<<endl;
    return 0;
}
