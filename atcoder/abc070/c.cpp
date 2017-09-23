#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

ll gcd(ll a,ll b){return b==0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(void){
    int N;
    cin>>N;
    ll res=1,t;
    rep(i,N){
        cin>>t;
        res = lcm(res,t);
    }
    cout<<res<<endl;
    return 0;
}
