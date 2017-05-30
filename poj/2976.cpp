#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
struct Test{
	ll a,b;
	bool operator<=(const Test& r)const{
		return (a*r.b==r.a*b ? b>=r.b : a*r.b<r.a*b);
	}
};

int main(void){
	int n,k;
	while(cin>>n>>k,n|k){
		vector<ll> a(n),b(n);
		vector<bool> used(n);
		rep(i,n)cin>>a[i];
		rep(i,n)cin>>b[i];
		Test sum = {0,0};
		rep(_,n-k){
			Test tmax = {0,0};
			int id;
			rep(i,n){
				if(used[i])continue;
				Test tmp = {sum.a+a[i],sum.b+b[i]};
				if(tmax.b==0 || tmax <= tmp){
					tmax = tmp;
					id = i;
				}
			}
			used[id] = true;
			sum = tmax;
		}
		printf("%.0f\n",(double)sum.a/(double)sum.b*100.0);
	}

	return 0;
}
