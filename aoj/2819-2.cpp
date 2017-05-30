#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
struct Trio{
	int to,v;
	ll cost;
	bool operator<(const Trio& right)const{
		return (cost > right.cost);
	}
};

int main(void){
	int n,m,v0,a,b,c;
	cin>>n>>m;
	vector<int> x(m),y(m);
	vector<ll> t(m);
	rep(i,m) cin>>x[i]>>y[i]>>t[i];
	cin>>v0>>a>>b>>c;
	vector<Trio> G[(n+1)*2][c];
	ll dp[(n+1)*2][c];
	rep(i,m)rep(v,c){
		int nextv=(a*v+b)%c;
		ll cost=t[i]*v;
		G[x[i]][v].push_back({y[i],nextv,cost});
		G[y[i]][v].push_back({x[i],nextv,cost});
		G[n+x[i]][v].push_back({n+y[i],nextv,cost});
		G[n+y[i]][v].push_back({n+x[i],nextv,cost});
	}
	rep(v,c) G[n][v].push_back({n*2,v,0});

	rep(i,(n+1)*2)rep(v,c) dp[i][v]=LLONG_MAX;
	dp[1][v0]=0;
	priority_queue<Trio,vector<Trio>> qu;
	qu.push({1,v0,0});
	while(qu.size()){
		Trio u=qu.top(); qu.pop();
		if(u.to==n+1){
			cout<<dp[u.to][u.v]<<endl;
			return 0;
		}
		if(dp[u.to][u.v] < u.cost)continue;
		for(auto e:G[u.to][u.v]){
			if(dp[e.to][e.v] > dp[u.to][u.v] + e.cost){
				dp[e.to][e.v] = dp[u.to][u.v] + e.cost;
				qu.push({e.to,e.v,dp[e.to][e.v]});
			}
		}
	}
}
