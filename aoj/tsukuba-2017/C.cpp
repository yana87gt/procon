#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n,t;
    cin>>n>>t;
    ll sum=0, cycle=0;
    rep(i,n) {
        ll h;
        cin>>h;
        cycle = max(cycle, h);
        ll tt = t-sum;
        ll res = tt/cycle + 1;
        if(tt%cycle >= h) res++;
        cout<<max(res,1LL)<<endl;
        sum += h;
    }
}
