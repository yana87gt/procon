#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
	int N,d,p,res=0;
	cin>>N>>d;
	rep(i,N){
		cin>>p;
		res+=max(0,p-d);
	}
	if(res==0)cout<<"kusoge"<<endl;
	else cout<<res<<endl;
	return 0;
}
