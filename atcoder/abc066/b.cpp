#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin>>s;
    int n = s.size();
    rep(i,n){
        s.pop_back();
        int m = s.size();
        if(m&1) continue;
        if(s.substr(0,m/2)==s.substr(m/2,m/2)){
            cout<<m<<endl;
            return 0;
        }
    }
    return 0;
}
