#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
struct edge{int to,cost;};
vector<vector<edge>> G;

int dfs(int v,int p,int s,int k) {
    int res=INT_MIN;
    for(auto e:G[v])if(e.to!=p){
        if(k>0 && e.to!=s) res=max(res,dfs(e.to,v,s,k-1)+e.cost);
        if(k==0 && e.to==s) return e.cost;    //k-ring
    }
    return (k==0 ? 0 : res);
}

int main(){
    int n,k,s;
    while(cin>>n>>k>>s,n|k|s){
        vector<int> x(n),y(n),z(n);
        rep(i,n) cin>>x[i]>>y[i]>>z[i];
        G.clear(), G.resize(n);
        rep(i,n)rep(j,n)if(i!=j){
            int sx = s-abs(x[i]-x[j]);
            int sy = s-abs(y[i]-y[j]);
            int sz = s-abs(z[i]-z[j]);
            if(min({sx,sy,sz})>0){
                G[i].push_back({j,2*(sx*sy+sy*sz+sz*sx)});
            }
        }
        int res=-1;
        rep(i,n) res=max(res,dfs(i,-1,i,k-1));
        cout<<(res>=0 ? s*s*6*k-res : -1)<<endl;
    }
    return 0;
}