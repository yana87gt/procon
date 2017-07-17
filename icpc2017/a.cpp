#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int n,m;
    while(cin>>n>>m, n|m){
        vector<int> a(n);
        int mx=0;
        rep(i,n)cin>>a[i];
        rep(i,n)rep(j,i){
            if(a[i]+a[j]<=m)mx=max(mx,a[i]+a[j]);
        }
        if(mx>0)cout<<mx<<endl;
        else cout<<"NONE"<<endl;
    }
    return 0;
}
