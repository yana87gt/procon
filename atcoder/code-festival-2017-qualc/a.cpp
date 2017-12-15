#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)


int main(void){
    string s;
    cin>>s;
    bool ok = false;
    rep(i,s.size()-1){
        if(s[i]=='A' && s[i+1]=='C') ok = true;
    }
    cout<<(ok ? "Yes" : "No")<<endl;
    return 0;
}
