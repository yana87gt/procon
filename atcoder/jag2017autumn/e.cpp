#include <bits/stdc++.h>
using namespace std;

#define N 100001
vector<int> g[N];
int dp[N],size[N];
int n,k,res=0;

void dfs(int par, int v){
    size[v] = 1;
    int kcnt = 0;
    vector<int> cc;
    for(int child : g[v]) if(child != par){
        dfs(v, child);
        size[v] += size[child];
        if(size[child] >= k) kcnt++;
        cc.push_back(dp[child] - (size[child] >= k));
    }
    sort(cc.begin(),cc.end(),greater<int>());

    // vが葉
    if(cc.size() == 0) return;

    // vがパスの下端点 or 連結成分が最大の子を選択
    dp[v] = max(kcnt, cc[0]+kcnt);
    
    // 親側を1つの連結成分として含める
    if(n-size[v] >= k) kcnt++;

    // vがパスの上端点
    res = max(res, cc[0]+kcnt);

    // vがパスの折り返し地点
    if(cc.size() >= 2){
        res = max(res, cc[0]+cc[1]+kcnt);
    }
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,1);
    cout<<res<<endl;
}
