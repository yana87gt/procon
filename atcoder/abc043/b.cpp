#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    string s;
    cin>>s;
    reverse(all(s));
    int n = s.size();
    int del = 0;
    rep(i,n){
        if(s[i]=='B'){
            del++;
        }else if(del>0){
            s[i] = 'B';
            del--;
        }
    }
    reverse(all(s));
    rep(i,n){
        if(s[i]!='B')cout<<s[i];
    }
    cout<<endl;
    return 0;
}
