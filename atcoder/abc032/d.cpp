#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;
int N,W;
vector<ll> v,w;

int main(void){
    cin>>N>>W;
    v.resize(N);
    w.resize(N);
    rep(i,N){
        cin>>v[i]>>w[i];
    }
    
    return 0;
}
