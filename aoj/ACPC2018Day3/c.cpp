#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)

vector<int> flags;
// 0: まだ
// 1: 行ってる
// 2: ループ
vector<vector<int>> g;

bool dfs(int v,int pre){
    flags[v] = 1;
    if(g[v].size() == 1 && g[v][0] == pre){
        return 0;
    }
    for(int to : g[v])if(to != pre){
        if(flags[to] == 1){
            flags[to] = 2;
            flags[v] = 2;
            return 1;
        }
        if(flags[to] == 0){
            if(dfs(to,v)){
                if(flags[v] == 2) return false;
                flags[v] = 2;
                return true;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    g.resize(n);
    flags.resize(n);
    rep(i,n){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    int Q;
    cin>>Q;
    rep(q,Q){
        int u,v;
        cin>>u>>v;
        u--,v--;
        if(flags[u] == 2 && flags[v] == 2){
            cout<<2<<endl;
        }else{
            cout<<1<<endl;
        }
    }
}