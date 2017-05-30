#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
struct Cow{
	int t,d;
	bool operator<(const Cow& right)const{
		return d*right.t > t*right.d;
	}
};

int main(void){
	ll N,sumT=0,res=0;
	cin>>N;
	vector<Cow> c(N);
	rep(i,N)cin>>c[i].t>>c[i].d;
	sort(c.begin(),c.end());
	rep(i,N-1){
		sumT+=c[i].t;
		res+=sumT*c[i+1].d;
	}
	cout<<res*2<<endl;
	return 0;
}
