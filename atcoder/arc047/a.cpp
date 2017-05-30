#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
	int N,L,cnt=1;
	cin>>N>>L;
	getchar();
	rep(i,N){
		if(getchar()=='+')cnt++;
		else cnt--;
	}
	cout<<(cnt-1)/L<<endl;
	return 0;
}
