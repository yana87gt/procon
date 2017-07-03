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

vector<int> a,b;

int bit[MAX_N+1],n;
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}

void add(int i,int x){
	while(i<=n){
		bit[i] +=x;
		i+=i&-1;
	}
}

int main(void){
	int n,m,k;
	cin>>n>>m>>k;
	a.resize(n+1);
	b.resize(n+1);
	rep1(i,n)cin>>a[i]>>b[i];
	rep(_,m){
		cin>>p>>q>>r;

	}

	return 0;
}
