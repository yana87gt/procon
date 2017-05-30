#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
int main(void){
	int H,W,res=0;
	cin>>H>>W;
	int cost[H+1][H+1]={},dp[H+1][H+1]={};
	string s[H+1];
	rep(y,H)cin>>s[y+1];
	rep(x,W-1){
		rep(i,H+1)rep(j,H+1)if(i&&j){
			cost[i][j] = cost[i-1][j-1] + (s[i][x]==s[j][x+1]);
			dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + cost[i][j];
		}
		res+=dp[H][H];
	}
	cout<<res<<endl;
	return 0;
}
