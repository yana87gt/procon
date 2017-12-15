#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

ll gcd(ll x,ll y){return y==0 ? x : gcd(y,x%y);}

ll a,b,res=0;
void solve(ll k,vector<ll> st){
    if(k==b+1){
        res++;
        return;
    }
    int m = st.size();
    solve(k+1,st);
    rep(i,m){
        if(gcd(k,st[i])!=1)return;
    }
    st.push_back(k);
    solve(k+1,st);
}
int main(void){
    cin>>a>>b;
    solve(a,{});
    cout<<res<<endl;
    return 0;
}
