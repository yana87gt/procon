#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
typedef long long ll;
struct edge{int to;ll cost;};
typedef pair<ll,int> P;
#define dist first
#define idx second
priority_queue<P,vector<P>,greater<P>> qu;

int a,b,c;
int nextv(int v){ return (a*v+b)%c;}

int main(void){
	int n,m,v0;
	cin>>n>>m;
	vector<int> x(m),y(m);
	vector<ll> t(m);
	rep(i,m) cin>>x[i]>>y[i]>>t[i];
	cin>>v0>>a>>b>>c;
	vector<edge> G[(n+1)*2*c];
	ll dp[(n+1)*2*c];
	rep(i,m)rep(v,c){
		G[x[i]*c+v].push_back({y[i]*c+nextv(v),t[i]*v});
		G[y[i]*c+v].push_back({x[i]*c+nextv(v),t[i]*v});
		G[(n+x[i])*c+v].push_back({(n+y[i])*c+nextv(v),t[i]*v});
		G[(n+y[i])*c+v].push_back({(n+x[i])*c+nextv(v),t[i]*v});
	}
	rep(v,c) G[n*c+v].push_back({n*2*c+v,0});

	rep1(i,n*2)rep(v,c) dp[i*c+v]=LLONG_MAX;
	dp[c+v0]=0;
	qu.push({0,c+v0});
	while(qu.size()){
		P u=qu.top(); qu.pop();
		if(u.idx/c==n+1){
			cout<<dp[u.idx]<<endl;
			return 0;
		}
		if(dp[u.idx] < u.dist)continue;
		for(auto e:G[u.idx]){
			if(dp[e.to] > dp[u.idx] + e.cost){
				dp[e.to] = dp[u.idx] + e.cost;
				qu.push({dp[e.to],e.to});
			}
		}
	}
}
