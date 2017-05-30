#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int T,N,x;
//pen,apple,pine
struct shop{int a,b,c,r;};
shop s[51];
int dp[101][51][51]={};

void dfs(int a,int b,int c){
	rep(i,N){
		int na=max(a-s[i].a,0),nb=max(b-s[i].b,0),nc=max(c-s[i].c,0);
		if( dp[na][nb][nc] > dp[a][b][c]+s[i].r){
			dp[na][nb][nc] = dp[a][b][c]+s[i].r;
			dfs(na,nb,nc);
		}
	}
}

int main(void){
	cin>>T;
	rep(_,T){
		cin>>N>>x;
		rep(i,N)cin>>s[i].a>>s[i].b>>s[i].c>>s[i].r;
		rep(i,2*x+1)rep(j,x+1)rep(k,x+1)dp[i][j][k]=INT_MAX;
		dp[x*2][x][x]=0;
		dfs(x*2,x,x);
		if(dp[0][0][0]==INT_MAX)cout<<-1<<endl;
		else cout<<dp[0][0][0]<<endl;
	}
	return 0;
}
