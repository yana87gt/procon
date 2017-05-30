#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
using namespace std;

int main(){
	int n;
	while(cin>>n,n){
		vector<string> s(n);
		rep(i,n)cin>>s[i];

		//s[i]がs[j]の部分文字列になっているかを調べる
		rep(a,n)rep(b,n){
			int A=s[a].size(),B=s[b].size();
			if(a==b || A<B || B==0) continue;
			rep(i,A-B+1)if(s[a].substr(i,B)==s[b])s[b]="";
		}
		rep(i,n)if(s[i]=="")swap(s[i--],s[--n]);
		//s.resize(n);

		//s[i],s[j]の順に並べるときの文字被りの数
		vector<vector<int>> cov(n,vector<int>(n,0));
		rep(i,n)rep(j,n)if(i!=j){
			int ct=min(s[i].size(),s[j].size());
			while(ct>0 && s[i].substr(s[i].size()-ct,ct)!=s[j].substr(0,ct))ct--;
			cov[i][j]=ct;
		}

		string INF(100,'z');

		//initialize
		string dp[10][1024];
		fill(dp[0],dp[10],INF);
		rep(i,n) dp[i][1<<i]=s[i];

		//現在の状態
		rep(mask,1<<n){
			//次に使おうと思ってるもの
			rep(i,n){
				if(mask>>i&1) continue;
				//どこからの遷移か(dp[j][mask])
				rep(j,n){
					if((mask>>j&1)==0) continue;
					string nx=dp[j][mask];
					string add=s[i].substr(cov[j][i]);
					nx+=add;
					if(dp[i][mask+(1<<i)].size()>nx.size())
						dp[i][mask+(1<<i)]=nx;
					else if(dp[i][mask+(1<<i)].size()==nx.size())
						dp[i][mask+(1<<i)]=min(dp[i][mask+(1<<i)],nx);
				}
			}
		}
		string ans=INF;
		rep(i,n){
			if(dp[i][(1<<n)-1].size()<ans.size()) ans=dp[i][(1<<n)-1];
			else if(dp[i][(1<<n)-1].size()==ans.size()) ans=min(ans,dp[i][(1<<n)-1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
