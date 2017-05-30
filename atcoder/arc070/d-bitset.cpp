#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
int N,K,a[5000];

bool need(int x) {
	if(a[x]>=K) return true;
	bitset<5000> s;
	s[0] = true;
	rep(i,N) if(i!=x) s |= (s<<a[i]);
	for(int i=K-a[x];i<K;i++) if(s[i]) return true;
	return false;
}

int main() {
	cin>>N>>K;
	rep(i,N) cin>>a[i];
	sort(a,a+N);
	int l=0,r=N;
	while(l<r){
		int mid = (l+r)/2;
		if(need(mid)) r = mid;
		else l = mid+1;
	}
	cout<<l<<endl;
	return 0;
}