#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

vector<ll> g[301][301];

int main(void){
    int N,M;
    cin>>N>>M;
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b].push_back(+c);
        g[b][a].push_back(-c);
    }

    return 0;
}
