#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define rep(i,n) for(int i=0;i<int(n);i++)
#define all(s) (s).begin(),(s).end()
#define pb push_back
using namespace std;

template<class Key>
using ordered_set = __gnu_pbds::tree<Key, __gnu_pbds::null_type, less<Key>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

using ll = long long;
const int N = 30000;
const ll INF = LLONG_MAX/3;

int n,k;
ll a[N],b[N],c[N];
ll sa[N],sb[N],sc[N];

//const int B = 2;
const int B = 174;
ll add[B]={};
ll x[B][B]={};
vector<ll> sorted_x[B];

ll f(int l, int r, ll m){
	int lid=l/B, rid=r/B;
	ll ret = 0;
	if(lid==rid){
		for(int i=l; i<=r; ++i){
			if(x[lid][i%B]+add[lid]<=m) ++ret;
		}
	}
	else{
		// left
		for(int i=l; i<B*(lid+1); ++i){
			if(x[lid][i%B]+add[lid]<=m) ++ret;
		}
		// right
		for(int i=B*rid; i<=r; ++i){
			if(x[rid][i%B]+add[rid]<=m) ++ret;
		}
		// middle
		for(int bid=lid+1; bid<rid; ++bid){
			int idx = upper_bound(all(sorted_x[bid]),m-add[bid])-sorted_x[bid].begin();
			ret += idx;
		}
	}
	return ret;
}

void ADD(int l, int r, ll v){
	int lid=l/B, rid=r/B;
	if(lid==rid){
		for(int i=l; i<=r; ++i) x[lid][i%B] += v;
		sorted_x[lid].clear();
		rep(i,B) sorted_x[i].pb(x[lid][i]);
		sort(all(sorted_x[lid]));
	}
	else{
		// left
		for(int i=l; i<B*(lid+1); ++i) x[lid][i%B] += v;
		sorted_x[lid].clear();
		rep(i,B) sorted_x[i].pb(x[lid][i]);
		sort(all(sorted_x[lid]));
		// right
		for(int i=B*rid; i<=r; ++i) x[rid][i%B] += v;
		sorted_x[rid].clear();
		rep(i,B) sorted_x[i].pb(x[rid][i]);
		sort(all(sorted_x[rid]));
		// middle
		for(int i=lid+1; i<rid; ++i) add[i] += v;
	}
}

// count not more than m
bool check(ll m, int r){
	// initialize
	fill(add,add+B,0);
	fill(x[0],x[B],INF);
	rep(i,B) sorted_x[i].clear();
	
	for(int i=1; i<=n-r; ++i){
		ll v = sa[n-1];
		v -= sa[r-1];
		v += sb[r-1];
		v -= (sa[i+r-1]-sa[i-1]);
		v += (sb[i+r-1]-sb[i-1]);
		if(i<=r-1){
			v -= 2*(sb[r-1]-sb[i-1]);
			v += (sa[r-1]-sa[i-1]);
			v += (sc[r-1]-sc[i-1]);
		}
		x[i/B][i%B] = v;
	}
	rep(i,B)rep(j,B) sorted_x[i].pb(x[i][j]);
	rep(i,B) sort(all(sorted_x[i]));
	
	ll ct=0;
	
	rep(i,n-r+1){
		// count
		ct += f(i+1,n-r,m);
		/*
		printf(" i=%d, ct %lld\n",i,ct);
		rep(j,4) printf(" %lld",x[0][j]+add[0]);
		printf("\n");
		*/
		if(i==n-r) break;
		// process for next
		int j=i+r;
		ADD(0,n-1,a[i]-b[i]);
		ADD(i+1,j,c[j]-b[j]);
		ADD(j+1,n-1,b[j]-a[j]);
	}
	
	//printf(" m= %lld, ct = %lld\n",m,ct);
	
	return ct>=k;
}

int main(){
	int r;
	cin >>n >>r >>k;
	rep(i,n) cin >>a[i];
	rep(i,n) cin >>b[i];
	rep(i,n) cin >>c[i];
	
	sa[0]=a[0];
	sb[0]=b[0];
	sc[0]=c[0];
	for(int i=1; i<n; ++i){
		sa[i] = sa[i-1]+a[i];
		sb[i] = sb[i-1]+b[i];
		sc[i] = sc[i-1]+c[i];
	}
	
	ll L=0, R=30000000003LL;
	while(R-L>1){
		ll m=(L+R)/2;
		if(check(m,r)) R=m;
		else L=m;
	}
	cout << R << endl;
	return 0;
} 
