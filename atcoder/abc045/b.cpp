#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    string s[3];
    rep(i,3){
        cin>>s[i];
        reverse(all(s[i]));
    }
    int man = 0;
    while(s[man]!=""){
        int next = s[man].back()-'a';
        s[man].pop_back();
        man = next;
    }
    cout<<char('A'+man)<<endl;
    return 0;
}
