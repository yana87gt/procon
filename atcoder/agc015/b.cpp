#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    string s;
    cin>>s;
    long long N=s.size(),res=0;
    rep(i,N){
        if(s[i]=='U')res+=(N-i-1)+i*2;
        else res+=(N-i-1)*2+i;
    }
    cout<<res<<endl;
    return 0;
}
