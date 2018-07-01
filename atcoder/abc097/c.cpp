#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)


int main(void){
    string s;
    int k;
    cin>>s>>k;
    int n = s.size();
    set<string> st;
    rep1(l,min(n,5)){
        rep(i,n-l+1){
            string sub = s.substr(i,l);
            st.insert(sub);
        }
    }
    for(auto str : st){
        k--;
        if(k==0){
            cout<<str<<endl;
            break;
        }
    }
    return 0;
}
