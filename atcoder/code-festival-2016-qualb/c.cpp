#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

int main(){
	ll W,H,c,res=0;
	cin>>W>>H;
	vector< pair<ll,bool> > v(W+H);
	rep(i,W+H){
		cin>>c;
		v[i]={c,i<W};
	}
	sort(v.begin(),v.end());
	W++;H++;
	for(auto t:v){
		if(t.second){
			res+=t.first*H;
			W--;
		}else{
			res+=t.first*W;
			H--;
		}
	}
	cout<<res<<endl;
	return 0;
}
