#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
typedef pair<int,int> Bug;
#define a second
#define b first
vector<Bug> bug;

int solve(int l,int r){
	if(l+1==r)return l;
	int k=(l+r)/2;
	ll sumA=0;
	priority_queue<int> pq;
	for(auto x:bug){
		sumA+=x.a;
		pq.push(x.a);
		if(pq.size()>k){
			sumA-=pq.top();
			pq.pop();
		}
		if(pq.size()==k && sumA<=(ll)k*x.b){
			return solve(k,r);
		}
	}
	return solve(l,k);
}

int main(void){
	int N;
	cin>>N;
	bug.resize(N);
	rep(i,N)cin>>bug[i].a>>bug[i].b;
	sort(bug.begin(),bug.end(),greater<Bug>());
	cout<<solve(0,N+1)<<endl;
	return 0;
}
