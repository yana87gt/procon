#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<int(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
using namespace std;
typedef unsigned long long ll;
map<ll,int> mpfact;
vector<ll> vcfact;

ll gcd(ll a,ll b){ return b==0 ? a : gcd(b,a%b); }

ll multi(ll a,ll b,ll m){
	if(b==0)return 0;
	return (a*(b&1)+multi((a<<1)%m,b>>1,m))%m;
}

ll power(ll n,ll r,ll m){
	if(r==0)return 1;
	return multi(power(multi(n,n,m),r>>1,m),(r&1 ? n : 1),m);
}

// ミラーラビン法
bool miller_rabin(ll n){
	ll q=n-1,k=0;
	// n-1 = 2^k * q (qは奇素数)
	while(q%2==0){ k++; q>>=1; }
	rep(i,12){
		ll a = rand() % (n-1) + 1; 
		ll x = power(a,q,n);
		// a^q ≡ 1 (mod n)
		if(x==1) continue;
		// a^q, a^2q,..., a^(k-1)q のどれかがnを法として-1
		bool found=true;
		rep(j,k){
			if(x==n-1)found=false;
			x = multi(x,x,n);
		}
		if(found)return false;
	}
	return true;
}

// ポラード・ロー素因数分解法
ll pollard_rho(ll n,int c) {
	ll x=2,y=2,d=1;
	while(d==1){
		x = multi(x,x,n)+c;
		y = multi(y,y,n)+c;
		y = multi(y,y,n)+c;
		d = gcd(x>y?x-y:y-x,n);
	}
	if(d==n)return pollard_rho(n,c+1);
	return d;
}

void factorize(ll n,ll p){
	for(;p<3000;p++){
		while(n%p==0){
			mpfact[p]++;
			n/=p;
		}
	}
	if(n==1)return;
	if(miller_rabin(n)){
		mpfact[n]++;
		return;
	}
	ll d = pollard_rho(n,1);
	factorize(d,p);
	factorize(n/d,p);
}

ll select(ll a,ll b,int i){
	if(i==(int)vcfact.size())return min(a,b);
	return max(select(a*vcfact[i],b,i+1),select(a,b*vcfact[i],i+1));
}

int main(void){
	ll G,L;
	while(cin>>G>>L){
		mpfact.clear();
		vcfact.clear();
		factorize(L/G,2);
		each(itr,mpfact){
			vcfact.push_back(power(itr->first,itr->second,ULLONG_MAX));
		}
		ll a = select(1,1,0);
		cout<<a*G<<" "<<L/a<< endl;
	}
	return 0;
}