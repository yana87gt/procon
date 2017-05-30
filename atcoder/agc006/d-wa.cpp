#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)

int N,a;
map<pair<int,int>,int> dp;

int mid(int y,int x){
	if(dp[{y,x}])return dp[{y,x}];
	int v[3];
	rep(i,3)v[i]=mid(y+1,x-1+i);
	sort(v,v+3);
	return dp[{y,x}]=v[1];
}

int main(void){
	cin>>N;
	rep1(i,2*N-1)cin>>a;
	cout<<mid(1,N)<<endl;
	return 0;
}
