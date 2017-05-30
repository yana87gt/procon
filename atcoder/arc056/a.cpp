#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll A,B,K,L,res;
    cin>>A>>B>>K>>L;
    if(K%L==0)res=K/L*B;
    else res=min(K/L*B+K%L*A,(K/L+1)*B);
    cout<<res<<endl;

    return 0;
}
