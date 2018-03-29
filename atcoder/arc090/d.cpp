#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e9
typedef pair<int,int> edge;
vector<vector<edge>> g;
vector<int> p;

bool solve(int v){
    if(abs(p[v]) > INF) return false;
    for(edge e : g[v]){
        int to = e.first;
        int d = e.second;
        if(p[to] == INF){
            p[to] = p[v] + d;
            if(!solve(to)) return false;
        }else if(p[v] + d != p[to]){
            return false;
        }
    }
    return true;
}

int main(void){
    int n,m;
    cin>>n>>m;
    g.resize(n);
    p.resize(n,INF);
    rep(_,m){
        int l,r,d;
        cin>>l>>r>>d;
        l--,r--;
        g[l].push_back({r,d});
        g[r].push_back({l,-d});
    }

    rep(i,n){
        if(p[i] != INF)continue;
        p[i] = 0;
        if(!solve(i)){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
