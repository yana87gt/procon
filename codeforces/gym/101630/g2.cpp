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

const int B = 100;
const int C = 300;
ll add[B]={};
ll x[B][C]={};

//vector<ll> sorted_x[B];
using P = pair<ll,int>;
ordered_set<P> sorted_x[B];

ll f(int l, int r, ll m){
	int lid=l/C, rid=r/C;
	ll ret = 0;
	if(lid==rid){
		for(int i=l; i<=r; ++i){
			if(x[lid][i%C]+add[lid]<=m) ++ret;
		}
	}
	else{
		// left
		for(int i=l; i<C*(lid+1); ++i){
			if(x[lid][i%C]+add[lid]<=m) ++ret;
		}
		// right
		for(int i=C*rid; i<=r; ++i){
			if(x[rid][i%C]+add[rid]<=m) ++ret;
		}
		// middle
		for(int bid=lid+1; bid<rid; ++bid){
			//int idx = upper_bound(all(sorted_x[bid]),m-add[bid])-sorted_x[bid].begin();
			int idx = sorted_x[bid].order_of_key({m-add[bid],191919});
			ret += idx;
		}
	}
	return ret;
}

void ADD(int l, int r, ll v){
	int lid=l/C, rid=r/C;
	if(lid==rid){
		for(int i=l; i<=r; ++i){
			sorted_x[lid].erase({x[lid][i%C], i});
			x[lid][i%C] += v;
			sorted_x[lid].insert({x[lid][i%C], i});
		}
	}
	else{
		// left
		for(int i=l; i<C*(lid+1); ++i){
			sorted_x[lid].erase({x[lid][i%C], i});
			x[lid][i%C] += v;
			sorted_x[lid].insert({x[lid][i%C], i});
		}
		// right
		for(int i=C*rid; i<=r; ++i){
			sorted_x[rid].erase({x[rid][i%C], i});
			x[rid][i%C] += v;
			sorted_x[rid].insert({x[rid][i%C], i});
		}
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
		x[i/C][i%C] = v;
	}
	rep(i,B)rep(j,C) sorted_x[i].insert({x[i][j], i*B+j});
	
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
	scanf("%d %d %d", &n, &r, &k);
	rep(i,n) scanf("%lld", a+i); //cin >>a[i];
	rep(i,n) scanf("%lld", b+i); //cin >>b[i];
	rep(i,n) scanf("%lld", c+i); //cin >>c[i];
	
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
