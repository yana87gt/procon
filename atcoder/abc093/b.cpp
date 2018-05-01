#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,k;
    cin>>a>>b>>k;
    set<int> st;
    for(int i=a; i<a+k && i<=b; i++){
        st.insert(i);
    }
    for(int i=max(b-k+1,a); i<=b; i++){
        st.insert(i);
    }
    for(int x:st){
        cout<<x<<endl;
    }
    return 0;
}