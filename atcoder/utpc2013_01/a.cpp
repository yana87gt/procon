#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin>>s;
    string hole0="CEFGHIJKLMNSTUVWXYZ";
    string hole1="ADOPQR";
    int cnt=0;
    rep(i,hole0.size()){
        if(s[0]==hole0[i])cnt++;
    }
    rep(i,hole0.size()){
        if(s[1]==hole0[i])cnt++;
    }
    rep(i,hole1.size()){
        if(s[2]==hole1[i])cnt++;
    }
    rep(i,hole0.size()){
        if(s[3]==hole0[i])cnt++;
    }
    cout<<(cnt==4 ? "yes" : "no")<<endl;
    return 0;
}
