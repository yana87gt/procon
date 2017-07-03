#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    string s="CODEFESTIVAL2016";
    string in;
    int cnt=0;
    cin>>in;
    rep(i,16){
        if(s[i]!=in[i])cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}
