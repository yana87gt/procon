#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

vector<ll> X,Y,Z;

void solve(){
	int N=X.size();
	if(N==0)return;
	ll sum,l=0,r=1LL<<32;
	while(l+1<r){
		sum=0;
		ll mid=(l+r)/2;
		rep(i,N) if(mid<=Y[i]) sum+=1+(Y[i]-max(mid,X[i]))/Z[i];
		if(sum%2==0)r=mid;
		else l=mid;
	}

	int cnt=0;
	rep(i,N) if(X[i]<=l && l<=Y[i] && (l-X[i])%Z[i]==0) cnt++;
	if(l==0)printf("no corruption\n");
	else printf("%lld %d\n",l,cnt);
}

int main(void){
	ll x,y,z;
	char input[40];
	bool isEnd=false;
	while(!isEnd){
		isEnd = fgets(input,sizeof(input),stdin)==NULL;
		if(input[0]=='\n' || isEnd){
			solve();
			X.clear();
			Y.clear();
			Z.clear();
		}else{
			sscanf(input,"%lld %lld %lld",&x,&y,&z);
			X.push_back(x);
			Y.push_back(y-(y-x)%z);
			Z.push_back(z);
		}
	}
	return 0;
}
