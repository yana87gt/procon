#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    set<string> st;

    rep(i,n){
        string s;
        cin>>s;
        st.insert(s);
    }
    cout<<(st.size()==3 ? "Three" : "Four")<<endl;
    return 0;
}

