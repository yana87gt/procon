#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(){
    ll n,m;
    cin>>n>>m;
    if(n>m) swap(n,m);
    if(m==1) return 1;
    if(n==1) return m-2;
    return (m-2)*(n-2);
}

int main(void){
    cout<<solve()<<endl;
    return 0;
}
