#include <cstdio>
#include <algorithm>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
typedef long long ll;
#define mod 100000000000000000LL
ll dp[1001][101][2]={};
void add(int N1,int K1,int N2,int K2){
	dp[N1][K1][0]+=dp[N2][K2][0];
	dp[N1][K1][1]+=dp[N2][K2][1]+dp[N1][K1][0]/mod;
	dp[N1][K1][0]%=mod;
}

void solve(int N,int K){
	if(N==0 || K==1)dp[N][K][0]=1;
	if(dp[N][K][0] || dp[N][K][1])return;
	rep1(i,min(N,K)){
		solve(N-i,i);
		add(N,K,N-i,i);
	}
}

int main(void){
	int N,K;
	scanf("%d%d",&N,&K);
	solve(N,K);
	if(dp[N][K][1])printf("%lld%017lld\n",dp[N][K][1],dp[N][K][0]);
	else printf("%lld\n",dp[N][K][0]);
	return 0;
}
