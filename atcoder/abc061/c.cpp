#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

int main(void){
    int N,a,b;
    ll K;
    cin>>N>>K;
    map<int,ll> mp;
    rep(i,N){
        cin>>a>>b;
        mp[a]+=b;
    }
    for(auto x:mp){
        K-=x.second;
        if(K<=0){
            cout<<x.first<<endl;
            break;
        }
    }
    return 0;
}
