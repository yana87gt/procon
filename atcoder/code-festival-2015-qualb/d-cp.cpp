#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
typedef long long ll;

#define INF 1LL << 62

int main(){
	int N;
	cin>>N;
	map<ll,ll> pos;
	pos[-1] = -1;
	pos[INF] = INF;
	rep(i,N){
		ll S,C;
		cin>>S>>C;
		auto it = --pos.upper_bound(S);
		ll SS = S;
		if(it->second >= S)SS = it->first;
		if(it->second > S)S = it->second;
		ll ans = 0;
		while(1){
			it = pos.lower_bound(S);
			if(it->first >= S + C){
				ans = S + C - 1;
				if(it->first == S + C)S = it->second;
				else S = ans + 1;
				break;
			}else{
				C -= (it->first - S);
				S = it->second;
			}
		}

		while(1){
			it = pos.lower_bound(SS);
			if(it->first < S)pos.erase(it);
			else break;
		}
		pos[SS] = S;
		cout<<ans<<endl;
	}
	return 0;
}
