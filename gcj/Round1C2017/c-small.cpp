#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
	int T,N,K;
	double U;
	cin>>T;
	rep(t,T) {
		cin>>N>>K>>U;
		vector<double> p(N);
		rep(i,N)cin>>p[i];
		sort(p.begin(),p.end());
		p.push_back(1.0);
		while(U>0){
			int x;
			double y;
			rep(i,N){
				if(p[i]<p[i+1]){
					x=i+1;
					y=p[x]-p[i];
					break;
				}
			}
			if(x*y<=U){
				rep(i,x)p[i]=p[x];
				U-=x*y;
			}else{
				rep(i,x)p[i]+=U/x;
				U=0;
			}
		}
		double res=1.0;
		rep(i,N)res*=p[i];
		printf("Case #%d: %.6f\n",t+1,res);
	}
	return 0;
}
