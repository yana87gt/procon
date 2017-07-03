#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll fact(ll n){
	return n==0 ? 1 : (n*fact(n-1))%MOD;
}

int main(void){
	int N,M;
	cin>>N>>M;
	ll res=1;
	if(abs(N-M)>1)res=0;
	if(abs(N-M)==0)res=2;
	res=(res*fact(N)*fact(M))%MOD;
	cout<<res<<endl;
	return 0;
}
