#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
	int N,K,a[5000];
	cin>>N>>K;
	rep(i,N) cin>>a[i];
	sort(a,a+N);

	int res=N;
	set<int> sum;
	sum.insert(0);
	for(int i=N-1;i>=0;i--){
		for(auto it=sum.rbegin();it!=sum.rend();++it){
			int next = *it+a[i];
			if(K<=next){
				res=i;
				break;
			}
			sum.insert(next);
		}
	}
	cout<<res<<endl;
	return 0;
}