#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin>>s;
    int res = 700;
    rep(i,3) if(s[i] == 'o') res += 100;
    cout<<res<<endl;
    return 0;
}
