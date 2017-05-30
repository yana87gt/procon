#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
	string s,y="yahoo";
	cin>>s;
	rep(i,5)rep(j,5)if(s[i]==y[j]){
		s[i]=y[j]=' ';
		break;
	}
	if(s=="     ")cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	return 0;
}
