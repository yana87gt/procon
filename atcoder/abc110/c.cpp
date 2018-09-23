#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s,t;
    cin>>s>>t;
    int n = s.size();
    vector<int> lastS(26,-1),lastT(26,-1);
    bool ok = true;
    rep(i,n){
        if(lastS[s[i]-'a'] != lastT[t[i]-'a']){
            ok = false;
        }
        lastS[s[i]-'a'] = i;
        lastT[t[i]-'a'] = i;
    }
    cout<<((ok) ? "Yes" : "No")<<endl;

    return 0;
}
