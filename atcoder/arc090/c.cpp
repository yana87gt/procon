#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    int res = 0;
    rep(k,n){
        int sum = 0;
        rep(x,k+1){
            sum += a[x];
        }
        for(int x=k;x<n;x++){
            sum += b[x];
        }
        res = max(res,sum);
    }
    cout<<res<<endl;
    return 0;
}
