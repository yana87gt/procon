#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
#define N 1000
#define N2 N*N
bool prime[N2+1];
int cave[N+2][N+2]={};
pair<int,int> locate[N2+1];
int last[N+2][N+2];
int dp[N+2][N+2];
int m,n;

bool wall(int x,int y){ return x==0 || y==0 || x==N+1 || y==N+1; }

int rec(int x,int y){
    int value = cave[x][y];
    if(wall(x,y) || value>m)return 0;
    if(dp[x][y])return dp[x][y];
    pair<int,int> child[3];
    rep(i,3)child[i]=pair<int,int>(rec(x+i-1,y-1),last[x+i-1][y-1]);
    sort(child,child+3);
    dp[x][y]=child[2].first;
    last[x][y]=child[2].second;
    if(prime[value])dp[x][y]++;
    if(last[x][y]==0 && prime[value]) last[x][y]=value;
    return dp[x][y];
}

int main(void){
    rep1(i,N2)prime[i]=true;
    prime[0]=prime[1]=false;
    for(int i=2;i<=N2;i++){
        if(prime[i]) for(int k=2;i*k<=N2;k++) prime[i*k]=false;
    }

    int x=1,y=N,d=0;
    int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
    for(int i=N2;i>0;i--){
        cave[x][y]=i;
        locate[i] = pair<int,int>(x,y);
        if(wall(x+dx[d],y+dy[d]) || cave[x+dx[d]][y+dy[d]]) d=(d+1)%4;
        x+=dx[d];
        y+=dy[d];
    }

    while(cin>>m>>n, m|n){
        rep1(x,N)rep1(y,N) dp[x][y]=last[x][y]=0;
        int x=locate[n].first,y=locate[n].second;
        int cnt = rec(x,y);
        cout<<cnt<<" "<<last[x][y];
    }

    return 0;
}
