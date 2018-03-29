#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin>>s;
    map<char,bool> mp;
    for(char c:s){
        mp[c] = true;
    }
    rep(i,26){
        if(!mp['a'+i]){
            printf("%c\n",'a'+i);
            return 0;
        }
    }
    cout<<"None"<<endl;
    return 0;
}
