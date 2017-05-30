#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
	int T;
	cin>>T;
	rep(t,T){
		string s;
		cin>>s;
		printf("Case #%d: ",t+1);
		int n=s.size();
		vector<int> d(n);
		rep(i,n){
			d[n-1-i]=s[i]-'0';
		}
		int last9=-1;
		rep(i,n-1){
			if(d[i+1]>d[i]){
				last9 = i;
				--d[i+1];
			}
		}
		if(d[n-1])cout<<d[n-1];
		for(int i=n-2;i>=0;i--){
			if(last9>=i)cout<<9;
			else cout<<d[i];
		}
		cout<<endl;
	} 
	return 0;
}
