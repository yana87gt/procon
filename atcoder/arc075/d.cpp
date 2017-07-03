#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
int N,A,B;
vector<int> h;

bool enough(int T){
	ll t=0;
	rep(i,N){
		ll r=h[i]-(ll)B*T;
		if(r>0)t+=(r-1)/(A-B)+1;
	}
	return t<=T;
}

int main(void){
	cin>>N>>A>>B;
	h.resize(N);
	rep(i,N)cin>>h[i];

	int ng=0,ok=1e9;
	while(ng+1<ok){
		int m=(ng+ok)/2;
		if(enough(m))ok=m;
		else ng=m;
	}
	cout<<ok<<endl;
	return 0;
}
