#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int solve(){
    int n;
    string s;
    cin>>n>>s;
    rep(i,n-1){
        if(s[i]=='x' && s[i+1]=='x'){
            return i+1;
        }
    }
    return n;
}

int main(void){
    cout<<solve()<<endl;
    return 0;
}
