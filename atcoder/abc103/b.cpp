#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    string s,t;
    cin>>s>>t;
    int n = s.size();
    bool ans = false;
    rep(i,n){
        if(s.substr(i,n-i)+s.substr(0,i) == t){
            ans = true;
        }
    }
    cout<<((ans) ? "Yes" : "No")<<endl;
    return 0;
}
