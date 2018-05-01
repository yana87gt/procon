#include <bits/stdc++.h>
using namespace std;

long sigma(long n){
    set<ll> st = {0,1};
    if (n == 0) return *st.begin();
    return n+sigma(n-1);
}

int main(void){
    cout<<sigma(100000)<<endl;
    return 0;
}
