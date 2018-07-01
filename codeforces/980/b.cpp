#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,k;
    cin>>n>>k;
    string s[4];
    rep(i,4) s[i] = string(n, '.');
    if(k==1){
        s[1][n/2] = '#';
    }else if(k==3){
        s[1][n/2] = '#';
        s[2][n/2-1] = s[2][n/2+1] = '#';
    }else{
        rep(i,(k+1)/2){
            s[1][i+1] = s[2][i+1] = '#';
        }
        if(k&1) s[1][2] = '.';
    }
    cout<<"YES"<<endl;
    rep(i,4) cout<<s[i]<<endl;
    return 0;
}
