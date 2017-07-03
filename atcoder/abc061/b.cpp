#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)

int main(void){
    int N,M,a,b;
    cin>>N>>M;
    vector<int> v(N+1);
    rep(i,M){
        cin>>a>>b;
        v[a]++;
        v[b]++;
    }
    rep1(i,N)cout<<v[i]<<endl;
    return 0;
}
