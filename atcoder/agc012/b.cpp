#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
int dp[100001],color[100001];
vector<int> e[100001];

void paint(int v,int d,int c){
    if(!color[v]) color[v]=c;
    if(dp[v]>=d || d==0)return;
    dp[v]=d;
    for(auto u:e[v]) paint(u,d-1,c);
}

int main(){
    int N,M,Q,a,b;
    cin>>N>>M;
    rep(i,M){
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    cin>>Q;
    int v[Q],d[Q],c[Q];
    rep(i,Q)cin>>v[i]>>d[i]>>c[i];
    for(int i=Q-1;i>=0;i--)paint(v[i],d[i],c[i]);
    rep(i,N)cout<<color[i+1]<<endl;
}