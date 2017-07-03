#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=n;++i)
typedef long long ll;

int main(void){
    int N;
    cin>>N;
    vector<ll> t(N+2),a(N+2);
    rep1(i,N)cin>>t[i];
    rep1(i,N)cin>>a[i];
    ll res=1;
    rep1(i,N){
        bool T = t[i]!=t[i-1];
        bool A = a[i]!=a[i+1];
        if(A||T){
            if((A && a[i]>t[i])||(T && t[i]>a[i]))res=0;
        }else{
            res=(res*min(t[i],a[i]))%1000000007;
        }
    }
    cout<<res<<endl;
    return 0;
}
