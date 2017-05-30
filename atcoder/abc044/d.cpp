#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll b,ll n){
	if(n<b) return n;
	else return f(b,n/b)+n%b;
}

ll solve(ll n,ll s){
	if(n==s)return n+1;
	if(n<s)return -1;

	ll i=2;
	for(;i*i<=n;i++){
		if(f(i,n)==s)return i;
	}

	for(;i>0;i--){
		if((n-s)%i==0 && f((n-s)/i+1,n)==s){
			return (n-s)/i+1;
		}
	}

	return -1;
}

int main(void){
	ll n,s;
	cin>>n>>s;
	cout<<solve(n,s)<<endl;
	return 0;
}
