#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin>>s;
    int n = s.size();
    s += " ";
    string choku[4] = {"ch","o","k","u"};
    rep(i,n){
        bool ok = false;
        bool ch = false;
        rep(j,4){
            int k = choku[j].size();
            if(s.substr(i,k) == choku[j]){
                ok = true;
                if(j==0) ch = true;
            }
        }
        if(!ok){
            cout<<"NO"<<endl;
            return 0;
        }
        if(ch) i++;
    }
    cout<<"YES"<<endl;
    return 0;
}
