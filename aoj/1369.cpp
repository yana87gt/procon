#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)

int main(void){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> v(m);
	vector<pair<int,int>> range(n);
	rep(i,n)range[i]={i,i};
	rep(i,m)cin>>v[i].first>>v[i].second;
	sort(v.begin(),v.end());
	rep(i,m){
		int y=v[i].second;
		range[y-1].second=range[y].second;
		range[y].first=range[y-1].first;
	}
	cout<<range[0].second-range[0].first+1;
	rep1(i,n-1)cout<<" "<<range[i].second-range[i].first+1;
	cout<<endl;
	return 0;
}
