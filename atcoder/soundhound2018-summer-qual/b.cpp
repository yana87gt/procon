#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    string s;
    int k;
    cin>>s>>k;
    rep(i,s.size()){
        if(i % k == 0){
            cout<<s[i];
        }
    }
    cout<<endl;
    return 0;
}
