#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    string s;
    cin>>s;
    int n = s.size();
    rep(i,n){
        string sub = s.substr(0,i);
        reverse(all(sub));
        string ss = s+sub;
        string ssr = ss;
        reverse(all(ssr));
        if(ss == ssr) {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
