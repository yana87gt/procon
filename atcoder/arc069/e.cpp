#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define x first
#define y second
typedef long long ll;

int main(void){
	int N;
	cin>>N;
	vector<pair<ll,int>> a(N+1);
	rep1(i,N){
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a.begin(),a.end(),greater<pair<ll,int>>());
	vector<ll> cnt(N+1);
	int min_y = N;
	rep(i,N){
		min_y = min(min_y,a[i].y);
		cnt[min_y] += (i+1)*(a[i].x-a[i+1].x);
	}
	rep1(i,N)cout<<cnt[i]<<endl;
	return 0;
}
