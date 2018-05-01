#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> imos(n+1);
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        imos[i+1] = imos[i] + a[i];
    }
    map<ll,int> his;
    his[0] = 1;
    ll res = 0;
    rep1(i,n){
        res += his[imos[i]];
        his[imos[i]]++;
    }
    cout<<res<<endl;

    return 0;
}
