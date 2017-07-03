#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n,ll d,ll s){
    if(n<=d)return s+n;
    return solve(n/d,10,s+n%d)+solve(n,d*10,s);
}

int main(void){
    ll n;
    cin>>n;
    cout<<solve(n,10,0)<<endl;
    return 0;
}
