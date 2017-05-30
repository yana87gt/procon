#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
	int n,k=0,cnt=0;
	string s,out="";
	cin>>n>>s;
	s+="W";
	rep(i,n+1){
		if(s[i]=='B'){
			if(cnt==0)k++;
			cnt++;
		}else if(cnt){
			if(k>1)out+=" ";
			out+=to_string(cnt);
			cnt=0;
		}
	}
	cout<<k<<endl;
	if(out!="")cout<<out<<endl;

	return 0;
}
