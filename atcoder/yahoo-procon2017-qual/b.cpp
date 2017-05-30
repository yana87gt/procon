#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

int main(void){
	int N,K;
	cin>>N>>K;
	vector<int> a(N);
	rep(i,N)cin>>a[i];
	sort(a.begin(), a.end());
	ll sum=0;
	rep(i,K)sum += i+a[i];
	cout<<sum<<endl;
	return 0;
}
