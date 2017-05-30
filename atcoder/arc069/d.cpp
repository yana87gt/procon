#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)

int main(){
	int N;
	string str;
	cin>>N>>str;
	vector<bool> s(N+1),a(N+2);
	rep(i,N) s[i] = str[i]=='o';
	s[N] = s[0];
	rep(x,2)rep(y,2){
		a[0]=x, a[1]=y;
		rep1(i,N) a[i+1] = a[i-1]==(a[i]==s[i]);
		if(a[0]==a[N] && a[1]==a[N+1]){
			rep(i,N)cout<<"WS"[a[i]];
			cout<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
