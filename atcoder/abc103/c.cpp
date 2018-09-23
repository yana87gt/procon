#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int n, res = 0;
    cin>>n;
    rep(i,n){
        int a;
        cin>>a;
        res += a-1;
    }
    cout<<res<<endl;
    return 0;
}
