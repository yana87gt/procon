#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define cost first
#define to second
typedef long long ll;
typedef pair<ll,int> edge;
#define MAX 100001
vector<edge> G[MAX];
ll dp[MAX][10];
priority_queue<edge,vector<edge>,greater<edge>> qu;

int main(){
	int N,M,R,Q,a,b,c;
	cin>>N>>M>>R>>Q;
	rep(i,M){
		cin>>a>>b>>c;
		G[b].push_back({c,a});
	}
	rep1(i,N)rep(r,R) dp[i][r] = LLONG_MAX/4;
	rep(r,R){
		rep1(i,N){
			if(i%R==r){
				dp[i][r]=0;
				qu.push({0,i});
			}
		}
		while(qu.size()){
			edge v=qu.top(); qu.pop();
			if(dp[v.to][r] < v.cost)continue;
			for(auto e:G[v.to]){
				if(dp[e.to][r] > dp[v.to][r] + e.cost){
					dp[e.to][r] = dp[v.to][r] + e.cost;
					qu.push({dp[e.to][r],e.to});
				}
			}
		}
	}
 
	ll res=0;
	rep(_,Q){
		int x,y,z;
		cin>>x>>y>>z;
		ll get=0;
		rep(r,R) get=max(get,z-(dp[x][r]+dp[y][r]));
		res += get;
	}
	cout<<res<<endl;
	return 0;
}