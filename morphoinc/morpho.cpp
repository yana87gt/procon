#include <bits/stdc++.h>
using namespace std;
int main(void){
	int n;
	cin>>n;
	long long h[n+2],maxS=0;
	for(int i=1;i<=n;++i)cin>>h[i];
	h[0] = h[n+1] = INT_MAX;
	int l=1,r=n;
	while(l<r){
		maxS = max(maxS,(r-l)*min(h[r],h[l]));
		int nl=l,nr=r;
		if(h[l]<=h[r])while(h[l]>=h[nl])nl++;
		if(h[l]>=h[r])while(h[nr]<=h[r])nr--;
		l=nl,r=nr;
	}
	cout<<maxS<<endl;
	return 0;
}
