#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

int a[100000]={},dp[100000]={};

int cost(int n){
    if(dp[n] || n<=1)return dp[n];
    return dp[n]=min(cost(n-2)+fabs(a[n]-a[n-2]),cost(n-1)+fabs(a[n]-a[n-1]));
}

int main(void){
    int N;
    cin>>N;
    rep(i,N)cin>>a[i];
    dp[1] = fabs(a[1]-a[0]);
    cout<<cost(N-1)<<endl;
    return 0;
}
