#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    string s;
    cin>>n>>s;
    int res = 0,x = 0;
    rep(i,n){
        if(s[i]=='I'){
            x++;
        }else{
            x--;
        }
        res = max(res,x);
    }
    cout<<res<<endl;
    return 0;
}
