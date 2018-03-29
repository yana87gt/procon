#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,m;
    cin>>n>>m;
    vector<string> a(n),b(m);
    rep(i,n) cin>>a[i];
    rep(i,m) cin>>b[i];
    rep(y,n-m+1)rep(x,n-m+1){
        bool ok = true;
        rep(i,m)rep(j,m)if(a[y+i][x+j] != b[i][j]) ok = false;
        if(ok){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
