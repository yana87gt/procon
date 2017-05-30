#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
	string s1,s2;
	cin>>s1>>s2;
	for(int L=min(s1.size(),s2.size());L>=1;L--){
		vector<int> a(26),b(26);
		set<vector<int>>st;
		rep(i,L)a[s1[i]-'a']++;
		rep(i,4000){
			st.insert(a);
			if(i+L==(int)s1.size())break;
			a[s1[i]-'a']--;
			a[s1[i+L]-'a']++;
		}

		rep(i,L)b[s2[i]-'a']++;
		rep(i,4000){
			if(st.find(b)!=st.end()){
				cout<<L<<endl;
				return 0;
			}
			if(i+L==(int)s2.size())break;
			b[s2[i]-'a']--;
			b[s2[i+L]-'a']++;			
		}
	}
	cout<<0<<endl;
	return 0;
}
