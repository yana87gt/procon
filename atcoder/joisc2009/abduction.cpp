#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
#define MOD 10000000

int main(void){
	int WH[2],N;
	string s;
	cin>>WH[0]>>WH[1]>>N>>s;
	vector<int> dir(N+1);//E,N,W,S
	dir[0] = (s[0]=='L' ? 0 : 1);
	rep(i,N){
		dir[i+1] = (dir[i]+(s[i]=='L' ? +1 : +3))%4;
	}

	ll res=1;
	if(s[0]!='L')swap(WH[0],WH[1]);
	rep(wh,2){
		int T=WH[wh];
		vector<ll> pre(T+1);
		pre[0]=1;
		for(int i=wh; i<=N; i+=2){
			vector<ll> v(T+1);
			int d = (dir[i]<2 ? +1 : -1);
			ll sum=0;
			for(int t=(d>0 ? 0 : T); 0<=t && t<=T; t+=d){
				v[t]=sum%MOD;
				sum+=pre[t];
			}
			pre=v;
		}
		res*=pre[T];
	}
	cout<<res%MOD<<endl;
	return 0;
}
