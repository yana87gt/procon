#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
int main(void){
    rep(i,3){
        string s;
        cin>>s;
        cout<<char(s[0]+'A'-'a');
    }
    cout<<endl;
    return 0;
}
