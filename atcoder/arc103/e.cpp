#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    string s;
    cin>>s;
    int n = s.size();
    s = "0" + s;
    if(s[1] == '0' || s[n-1] == '0' || s[n] == '1'){
        cout<<-1<<endl;
        return 0;
    }
    
    rep1(i,n/2){
        if(s[i] != s[n-i]){
            cout<<-1<<endl;
            return 0;
        }
    }

    int head = 1;
    rep1(i,n-1){
        cout<<head<<" "<<i+1<<endl;
        if(s[i] == '1') head = i+1;
    }
    return 0;
}
