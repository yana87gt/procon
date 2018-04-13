#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    set<int> st;
    rep(i,3){
        int x;
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<endl;
    
    return 0;
}
