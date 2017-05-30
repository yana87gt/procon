#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
typedef long long ll;
typedef pair<ll,ll> Cake;
#define side first
#define bottom second

int main(void){
	int T,N,K;
	ll r,h;
	cin>>T;
	rep1(t,T){
		cin>>N>>K;
		vector<Cake> c(N);
		rep(i,N){
			cin>>r>>h;
			c[i].side=2*r*h;
			c[i].bottom=r*r;
		}
		sort(c.begin(),c.end(),greater<Cake>());
		ll area=0,res=0;
		rep(i,K-1)area+=c[i].side;
		rep(i,N){
			if(i<K)res=max(res,area+c[i].bottom+c[K-1].side);
			else res=max(res,area+c[i].bottom+c[i].side);
		}
		printf("Case #%d: %.9f\n",t,res*M_PI);
	}
	return 0;
}
