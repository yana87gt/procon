#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
	int T,N,M,L;
	cin>>T;
	rep(_,T){
		cin>>N>>M>>L;
		vector<int> p(N),q(N),x(M),y(M);
		vector<bool> g(M);
		rep(i,N)cin>>p[i]>>q[i];
		rep(j,M)cin>>x[j]>>y[j];
		rep(i,N)rep(j,M){
			if((p[i]-x[j])*(p[i]-x[j])+(q[i]-y[j])*(q[i]-y[j])<=L*L){
				g[j]=true;
			}
		}
		int cnt=0;
		rep(j,M)cnt+=g[j];
		cout<<cnt<<endl;
	}
	return 0;
}
