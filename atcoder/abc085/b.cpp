#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,x;
    cin>>n;
    set<int> st;
    while(n--){
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<endl;
    return 0;
}
