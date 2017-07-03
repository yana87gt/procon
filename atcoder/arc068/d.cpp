#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int N,a;
    cin>>N;
    set<int> st;
    rep(i,N){
        cin>>a;
        st.insert(a);
    }
    int res = st.size();
    if(res%2==0)res--;
    cout<<res<<endl;

    return 0;
}
