#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,T,pre=0,t,sum=0;
	cin>>N>>T;
	while(N--){
		cin>>t;
		sum+=min(t-pre,T);
		pre=t;
	}
	cout<<sum+T<<endl;
}
