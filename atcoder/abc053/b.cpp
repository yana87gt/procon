#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin>>s;
    int n = s.size();
    int l,r;
    rep(i,n){
        if(s[i]=='A') {
            l=i;
            break;
        }
    }
    rep(i,n){
        if(s[i]=='Z') r=i;
    }
    cout<<r-l+1<<endl;
    return 0;
}
