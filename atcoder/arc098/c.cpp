#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    string s,rs;
    cin>>n>>s;
    rs = s;
    vector<int> lw(n), re(n);
    int pre = 0;
    rep(i,n){
        lw[i] = pre;
        if(s[i] == 'W'){
            pre++;
        }
    }
    pre = 0;
    for(int i = n-1; i>=0; i--){
        re[i] = pre;
        if(s[i] == 'E'){
            pre++;
        }
    }
    int res = n;
    rep(i,n){
        res = min(lw[i]+re[i],res);
    }
    cout<<res<<endl;
    return 0;
}
