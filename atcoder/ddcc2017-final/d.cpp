#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

vector<int> g[51];
vector<int> id;

int solve(){
    int N;
    cin>>N;
    id = vector<int>(N+1,INF);
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        if(g[a].size()>4 || g[b].size()>4) return 0;
    }

    rep1(i,N){
        cnt += g[i].size()>3
    }

    ll res = 3;
    rep(i,N-2){
        res = (res*2)%1000000007;
    }
    return int(res);

}

int main(void){
    cout<<solve()<<endl;
    return 0;
}
