#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
struct man{int n,order;};
bool comp(man a,man b){return a.n<b.n;}

int main(void){
    ll n;
    int q;
    cin>>n>>q;
    ll *d = new ll[1<<(q+1)];
    int a[25]={};
    rep1(i,q)cin>>a[i];

    d[1]=1;
    rep1(i,q)
    {
        rep1(j,1<<(i-1))
        {
            d[(1<<(i-1))+j] = (d[j]>n ? n+1 : d[j]*a[i]);
            rep1(k,1<<q)cout<<d[k]<<" ";
            cout<<endl;
        }
    }

    set<ll> p;
    rep1(i,1<<q)if(d[i]<=n)p.insert(d[i]);
    cout<<p.size()<<endl;


    return 0;
}
