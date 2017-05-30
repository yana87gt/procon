#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

int main(void){
	int T;
	cin>>T;
	rep(t,T){
		ll N,K;
		cin>>N>>K;
		map<ll,ll> s;
		s[N]=1;
		while(1){
			ll i=s.rbegin()->first;
			if(K<=s[i]){
				printf("Case #%d: %lld %lld\n",t+1,i/2,(i-1)/2);
				break;
			}
			K-=s[i];
			s[i/2]+=s[i];
			s[(i-1)/2]+=s[i];
			s.erase(i);
		}
	} 
	return 0;
}