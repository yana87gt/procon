#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int N,b=0;
    string s;
    cin>>N>>s;
    rep(i,N){
        if(s[i]=='(')b++;
        else if(b>0)b--;
        else cout<<"(";
    }
    cout<<s;
    rep(i,b)cout<<")";
    cout<<endl;
    return 0;
}
