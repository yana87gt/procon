#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

ll dsum(ll n){
    int res = 0;
    while(n>0){
        res += n%10;
        n /= 10;
    }
    return res;
}

int main(void){
    ll n;
    cin>>n;
    ll d = 10;
    ll res = dsum(n);
    while(d<=n){
        res = max(res,dsum(n - n%d - 1));
        d *= 10;
    }
    cout<<res<<endl;
    return 0;
}

