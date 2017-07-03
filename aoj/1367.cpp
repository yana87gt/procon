#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)

int main(void){
    int n,m;
    cin>>n>>m;
    vector<int> v(m);
    vector<bool> used(n+1);
    rep(i,m)cin>>v[i];
    reverse(v.begin(), v.end());
    rep(i,m){
        if(!used[v[i]])cout<<v[i]<<endl;
        used[v[i]]=true;
    }
    rep1(i,n)if(!used[i])cout<<i<<endl;
    return 0;
}
