#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
typedef long long ll;

int y[51];
ll dp[51][5001];
int N,A,X=0;
ll solve(int j,int t){
    if(dp[j][t]>=0)return dp[j][t];
    if(j==0 && t==N*X)return dp[j][t]=1;
    else if(j>0 && (t-y[j]<0 || t-y[j]>2*N*X))return dp[j][t]=solve(j-1,t);
    else if(j>0)return dp[j][t]=solve(j-1,t)+solve(j-1,t-y[j]);
    else return dp[j][t]=0;
}

int main(void){
    cin>>N>>A;
    rep1(i,N){
        cin>>y[i];
        y[i]-=A;
        X=max(y[i],X);
    }
    rep(i,N+1)rep(j,2*N*X+1)dp[i][j]=-1;
    cout<<solve(N,N*X)-1<<endl;
    return 0;
}
