#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define mod 1000000007
using namespace std;
typedef long long ll;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int number[1002][1002]={};
ll dp[1002][1002]={};
int H,W;

ll route(int y,int x){
    if(dp[y][x])return dp[y][x];
    if(y==0 || y==H+1 || x==0 || x==W+1)return 0;
    dp[y][x]=1;
    rep(i,4) if(number[y][x] > number[y+dy[i]][x+dx[i]]) dp[y][x] += route(y+dy[i],x+dx[i]);
    return dp[y][x]%=mod;
}

int main(void){
    ll sum=0;
    scanf("%d %d",&H,&W);
    rep1(y,H)rep1(x,W)scanf("%d",&number[y][x]);
    rep1(y,H)rep1(x,W)sum+=route(y,x);
    printf("%lld\n",sum%mod);
    return 0;
}
