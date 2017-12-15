#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

int main(void){
    string s;
    cin>>s;
    reverse(all(s));
    int idx;
    rep(i,12){
        if(s[i]=='?'){
            idx = i;
        }
    }
    int res,ok=0;
    rep(k,10){
        s[idx] = '0'+k;
        ll sigma = 0;
        rep1(n,11){
            sigma += (s[n]-'0')*((n<=6) ? (n+1) : (n-5));
        }
        int check = 11-(sigma%11);
        if((sigma%11)<=1) check = 0;
        if(check == s[0]-'0'){
            ok++;
            res=k;
        }
    }
    if(ok>1){
        cout<<"MULTIPLE"<<endl;
    }else{
        cout<<res<<endl;
    }
    return 0;
}
