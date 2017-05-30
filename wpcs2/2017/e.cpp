#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)

int NP(string &s,int i,int N){
	while(i<N){
		if(s[i]=='N')i++;
		else if(s[i]=='P')return i+1;
		else return -1;
	}
	return -1;
}

bool solve(){
	string s,ppap="PPAP";
	cin>>s;
	int N=s.size();
	int i=0;
	i = NP(s,i,N);
	if(i==-1)return false;
	i = NP(s,i,N);
	if(i==-1)return false;
	if(s[i]=='A')i++;
	i = NP(s,i,N);
	return i==N;
}

int main(void){
	int T;
	cin>>T;
	rep(_,T){
		cout<<(solve()?"YES":"NO")<<endl;
	}
	return 0;
}
