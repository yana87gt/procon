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
	int T;
	string s;
	cin>>T;
	rep(_,T){
		cin>>s;
		int o=0,dot=0;
		for(char c:s){
			if(c=='o')o++;
			if(c=='.')dot++;
		}
		rep(i,dot)cout<<".";
		rep(i,o)cout<<"o";
		cout<<endl;
	}
	return 0;
}
