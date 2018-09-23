#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    int res = 0;
    rep(i,n){
        int x,y;
        cin>>x>>y;
        res = max(res, x+y);
    }
    cout<<res<<endl;
    return 0;
}
