#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s,t;
    cin>>s>>t;
    int n = s.size(), m = t.size();
    int pos = -1;
    rep(i,n-m+1){
        bool ok = true;
        rep(j,m){
            if(s[i+j]=='?')continue;
            if(s[i+j]!=t[j])ok=false;
        }
        if(ok)pos=i;
    }
    if(pos>=0){
        rep(j,m) s[pos+j]=t[j];
        rep(i,n) if(s[i]=='?') s[i] = 'a';
        cout<<s<<endl;
    }else{
        cout<<"UNRESTORABLE"<<endl;
    }
    return 0;
}
