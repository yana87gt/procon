#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
	int N,a,f=0;
	cin>>N;
	map<int,bool> color;
	rep(i,N){
		cin>>a;
		if(a>=3200)f++;
		else color[a/400]=true;
	}
	int C=color.size();
	cout<<max(C,1)<<" "<<C+f<<endl;
	return 0;
}
