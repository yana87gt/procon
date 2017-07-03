#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

typedef long long ll;

int main(void){
	ll A,B,X,a,t=0;
	cin>>A>>B>>X;
	a=A;
	map<ll,bool> visit;
	visit[a]=1;
	while(a!=X){
		a=(a/2)^(a%2*B);
		t++;
		if(visit[a]){
			t=-1;
			break;
		}
		visit[a]=1;
	}
	cout<<t<<endl;
	return 0;
}
