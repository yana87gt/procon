#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=n;++i)
int main(){
	int N,p;
	cin>>N;
	int add[N+1];
	rep1(i,N)cin>>p,add[p]=i;
	rep1(i,N)cout<<i*N<<" ";
	cout<<endl;
	rep1(i,N)cout<<N*(N-i)+add[i]<<" ";
	cout<<endl;
}
