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
	int T,x;
	cin>>T;
	rep(_,T){
		cin>>x;
		x%=4;
		x=4-x;
		cout<<x%4<<endl;
	}
	return 0;
}
