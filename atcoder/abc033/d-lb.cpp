#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define ub(s,x) upper_bound(all(s),x)-s.begin()
typedef long long ll;
double EPS = 1e-10;

int main() {
	int N;
	cin>>N;
	vector<ll> x(N),y(N);
	rep(i,N)cin>>x[i]>>y[i];
	ll cho=0,don=0;
	rep(i,N){
		vector<double> a;
		rep(j,N)if(j!=i)a.push_back(atan2(y[j]-y[i],x[j]-x[i]));
		sort(all(a));
		rep(j,N-1)a.push_back(a[j]+M_PI*2);
		rep(j,N-1){
			int xc = lb(a,a[j]+M_PI/2-EPS);
			int yc = ub(a,a[j]+M_PI/2+EPS);
			int zc = lb(a,a[j]+M_PI);
			cho += yc-xc;
			don += zc-yc;
		}
	}
	ll ei = (ll)N*(N-1)*(N-2)/6-cho-don;
	cout<<ei<<" "<<cho<<" "<<don<<endl;
}
