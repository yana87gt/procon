#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

using ll = long long;

char solve(){
    string s;
    ll k;
    cin>>s>>k;
    if(k==1) return s[0];
    ll n = s.size();    
    rep(i,min(n,k)){
        if(s[i]!='1') return s[i];
    }
    return '1';
}
int main(void){
    cout<<solve()<<endl;
    return 0;
}
