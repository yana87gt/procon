#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 8e6
typedef long long ll;

int N,M,R;
int edge[200][200]={};
int d[8][8];

int dfs(int mask,int v){

}

int main(void){
    cin>>N>>M>>R;
    vector<int> r(R);
    rep(i,R) cin>>r[i],r[i]--;
    rep(i,200) rep(j,200) edge[i][j]=INF;
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        edge[a][b]=c;
        edge[b][a]=c;
    }

    rep(i,N)rep(j,N)rep(k,N) edge[j][k] = min(edge[j][k], edge[j][i] + edge[i][k]);


    int res=INF;

    rep(i,R)rep(j,R) d[i][j] = edge[r[i]][r[j]];
    rep(i,R) d[i][i] = 0;
    rep(start,R){
//        res=min(res,dfs(1<<start,start));
    }
    cout<<res<<endl;

    return 0;
}
