#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
	string s;
	int K;
	cin>>s>>K;
	rep(i,(int)s.size()){
		if('z'-s[i]<K && s[i]!='a'){
			K -= 'z'-s[i]+1;
			s[i]='a';
		}
	}
	s[(int)s.size()-1] += K%26;
	cout<<s<<endl;

	return 0;
}
