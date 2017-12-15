#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

vector<int> g[50];

int dfs(int v,int a,int b,vector<bool> &visited){
    if(visited[v]) return 0;
    visited[v] = true;
    int cnt=1;
    for(int to : g[v]){
        if((v==a && to==b)||(v==b && to==a))continue;
        cnt += dfs(to,a,b,visited);
    }
    return cnt;
}

int main(void){
    int N,M;
    cin>>N>>M;
    vector<int> a(M),b(M);
    rep(i,M){
        cin>>a[i]>>b[i];
        a[i]--,b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    int cnt=0;
    rep(i,M){
        vector<bool> visited(N,false);
        if(dfs(0,a[i],b[i],visited)!=N)cnt++;
    }
    cout<<cnt<<endl;
}
