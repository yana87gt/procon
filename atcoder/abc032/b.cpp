#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    int k;
    cin>>s>>k;
    int n = s.size();
    set<string> st;
    rep(i,n-k+1){
        st.insert(s.substr(i,k));
    }
    cout<<st.size()<<endl;
    return 0;
}
