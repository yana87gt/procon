#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
	int N,sum=0;
	int L[200];
	cin>>N;
	rep(i,2*N)cin>>L[i];
	sort(L,L+2*N);
	rep(i,N)sum+=L[i*2];
	cout<<sum<<endl;
	return 0;
}
