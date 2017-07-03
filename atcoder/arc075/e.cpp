#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

template<typename Type>

class BIT {
	public: //1-index
	vector<Type> bit;
	int n;
	BIT(int size){
		n = size+1;
		bit = vector<Type>(n+1,0);
	}

	void add(int i,Type x){
		while(i<=n){
			printf("add : i=%d x=%lld\n",i,x );
			bit[i] += x;
			i += i&-i;
		}
	}

	Type sum(int i){
		int ret=0;
		while(i>0){
			printf("sum : i=%d\n",i);
			ret += bit[i];
			i -= i&-i;
		}
		return ret;
	}

	Type range(int l,int r){
		return sum(r)-sum(l-1);
	}
};

int main(void){
	ll N,K,a,sum=0;
	cin>>N>>K;
	vector<pair<ll,int>> b(N+1);
	rep(j,N){
		cin>>a;
		b[j]={sum-j*K,j};
		sum+=a;
	}
	b[N]={sum-N*K,N};

	sort(all(b));
	BIT<int> bit(N);
	ll res=0;
	cout<<"bit created"<<endl;
	rep1(i,N){
		res += bit.sum(b[i].second);
		bit.add(b[i].second,1);
	}
	cout<<res<<endl;

	return 0;
}
