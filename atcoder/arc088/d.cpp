#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin>>s;
    int n = s.size();
    int k = n;
    rep(i,n-1){
        if(s[i]!=s[i+1]) k = min(k,max(n-i-1,i+1));
    }
    cout<<k<<endl;
    return 0;
}
