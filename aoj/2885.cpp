#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); i++)

bool coloring(int c, int v, vector<int> &color,vector<vector<int>> &g){
    if(color[v] == -c) return false;
    if(color[v] != 0) return true;
    color[v] = c;
    for(int to : g[v]){
        if(!coloring(-c,to,color,g)) return false;
    }
    return true;
}

int main(){
    int n,m;
    while(cin>>n>>m, n|m){
        vector<vector<int>> g(n);
        rep(i,m){
            int v,u;
            cin>>v>>u;
            v--, u--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> color(n);
        if(!coloring(1,0,color,g)){
            cout<<0<<endl;
            continue;
        }
        int red = 0, black = 0;
        rep(i,n){
            if(color[i] == 1) red++;
            else black++;
        }

        set<int> res;
        if(red % 2 == 0) res.insert(red/2);
        if(black % 2 == 0) res.insert(black/2);
        cout<<res.size()<<endl;
        for(int p : res){
            cout<<p<<endl;
        }

    }
    return 0;
}
