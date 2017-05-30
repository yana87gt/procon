#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)

int solve(int N){
	if(N>=2017)return 0;
	if(N==0)return 1;
	return (N*solve(N-1))%2017;
}

int main(void){
	int T,N;
	cin>>T;
	rep(_,T){
		cin>>N;
		cout<<solve(N)<<endl;
	}
	return 0;
}
