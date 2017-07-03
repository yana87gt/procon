#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
struct Point{
	double x,y;
	bool operator<(const Point& right)const{
		return (x==right.x ? y<right.y : x<right.x);
	}
};

int main(void){
	ll N,K;
	cin>>N>>K;
	vector<int> a(N),s(N+1);
	rep(i,N)cin>>a[i], s[i+1]=s[i]+a[i];

	ll r=1,sum=0,res=0;
	rep(l,N){
		while(r<N && sum<K*(r-l)){
			sum+=a[r++];
			printf("[l,r)=[%d,%lld) , sum=%lld\n",l,r,sum );
		}

		res+=r-l-1;
		printf("r-l-1=%lld , res=%lld\n",r-l-1,res);
		sum-=a[l];
	}
	cout<<res<<endl;
	
	return 0;
}
