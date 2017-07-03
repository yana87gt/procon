#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define each(it,c) for(auto it=c.begin();it!=c.end();++it)
vector<set<int>> p(200000);
bool used[200000]={};
int N,M,S;

bool move(int to,int n){
    if(used[n])return false;
    each(it,p[n]) (*it);
}

int main(){
    cin>>N>>M>>S;
    int u,v;
    rep(i,M){
        cin>>u>>v;
        p[u].insert(v);
        p[v].insert(u);
    }

    rep1(i,N){
        if(move(i,S))
    }
    return 0;
}