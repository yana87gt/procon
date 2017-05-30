#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define N 800
typedef long long ll;
int n;
pair<int,pair<int,int>> b[N+1];//<p[i],<i,d[i]>>


int main(void){
	while(cin>>n,n){
		vector<int> p(n+1),d(n+1); 
		for(int i=2;i<=n;i++) cin>>p[i];
		for(int i=2;i<=n;i++) cin>>d[i];
		for(int i=2;i<=n;i++){
			G[i].push_back({d[i],p[i]});
			G[p[i]].push_back({d[i],i});
		}
		ll sum=0;
		rep(i,n-1){
			cin>>b[i].second.second;
			sum+=b[i].second.second;
		}
		sort(b,b+N-1);

	}

	return 0;
}
