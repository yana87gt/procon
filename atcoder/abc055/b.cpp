#include <bits/stdc++.h>
using namespace std;
#define mod ll(1e9+7)
typedef long long ll;

ll fact(ll n){
    if(n==1) return 1;
    return n*fact(n-1)%mod;
}

int main(void){
    int n;
    cin>>n;
    cout<<fact(n)<<endl;
    return 0;
}
