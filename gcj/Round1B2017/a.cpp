#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
typedef long long ll;

int main(void){
	int T,D,N;
	cin>>T;
	rep1(t,T){
		cin>>D>>N;
		int K,S;
		double max_time=0;
		rep(i,N){
			cin>>K>>S;
			max_time=max(max_time,(double)(D-K)/S);
		}
		printf("Case #%d: %.7f\n",t,D/max_time);
	}
	return 0;
}
