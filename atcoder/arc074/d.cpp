#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

int main(void){
	int N,x;
	cin>>N;
	vector<ll> a(N),suml(N+1),sumr(N+1);
	priority_queue<int,vector<int>,greater<int>> lq;
	priority_queue<int> rq;	
	rep(i,N)cin>>x, suml[0]+=x, lq.push(x);
	rep(i,N)cin>>a[i];
	rep(i,N)cin>>x, sumr[N]+=x, rq.push(x);
	rep(k,N){
		lq.push(a[k]);
		suml[k+1] = suml[k]+a[k]-lq.top();
		lq.pop();
		rq.push(a[N-1-k]);
		sumr[N-1-k] = sumr[N-k]+a[N-1-k]-rq.top();
		rq.pop();
	}
	ll res=LLONG_MIN;
	rep(k,N+1)res=max(res,suml[k]-sumr[k]);
	cout<<res<<endl;
	return 0;
}
