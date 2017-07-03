#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

int N,W,w0,wi,vi;
vector<ll> v[4];

ll solve(int k,int n,ll wsum,ll vsum){
    if(wsum>W)return 0;
    if(k==4)return vsum;
    if(n==(int)v[k].size())return solve(k+1,0,wsum,vsum);
    return max(solve(k,n+1,wsum+w0+k,vsum+v[k][n]),solve(k+1,0,wsum,vsum));
}

int main(void){    
    cin>>N>>W>>w0>>vi;
    v[0].push_back(vi);
    rep(i,N-1){
        cin>>wi>>vi;
        v[wi-w0].push_back(vi);
    }
    rep(k,4)sort(all(v[k]),greater<ll>());
    cout<<solve(0,0,0,0)<<endl;
    return 0;
}
