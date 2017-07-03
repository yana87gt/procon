#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int N;
	cin>>N;
	map<ll,ll> seg;//<right,left> (left,right]
	seg[-1]=-1;
	seg[LLONG_MAX]=LLONG_MAX;
	while(N--){
		ll s,c;
		cin>>s>>c;
		s--;
		while(1){
			auto ub = seg.upper_bound(s);
			ll l=ub->second,r=ub->first;
			if(s+c<=l){
				cout<<s+c<<endl;
				seg[s+c]=s;
				break;
			}else{
				c+=r-l;
				s=min(s,l);
				seg.erase(ub);
			}
		}
	}
	return 0;
}
