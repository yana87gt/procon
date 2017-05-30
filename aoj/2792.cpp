#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=n;++i)

int main(void){
	long long A,B,N,res=LLONG_MAX;
	cin>>A>>B>>N;
	rep1(i,N)rep1(j,N){
		if(B*j%i==0){
			res = min(res,abs(B*j/i - A));
		}
	}
	cout<<res<<endl;
	return 0;
}
