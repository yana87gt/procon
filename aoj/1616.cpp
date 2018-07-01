#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,m;
    while(cin>>n>>m, n|m){
        vector<int> a(n);
        rep(i,n){
            cin>>a[i];
        }
        int res = 0;
        rep(i,n)rep(j,i){
            int sum = a[i]+a[j];
            if(sum <= m){
                res = max(res,sum);
            }
        }
        if(res == 0) cout<<"NONE"<<endl;
        else cout<<res<<endl;
    }    
    return 0;
}
