#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n,ll k){
    ll res = 0;
    if(k==0) return n*n;
    for (int b=k+1;b<=n;b++){
        res += (b-k)*(n/b) + max(n%b-k+1,0LL);
    }
    return res;
}

int main(void){
    ll n,k;
    cin>>n>>k;
    cout<<solve(n,k)<<endl;
    return 0;
}
