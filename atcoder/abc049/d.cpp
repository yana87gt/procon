#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

struct UnionFind{
    vector<int> par;
    vector<int> sizes;
    UnionFind(int n):par(n),sizes(n,1){ rep(i,n)par[i]=i; }

    //find root of x
    int find(int x){
        if(x!=par[x]) par[x] = find(par[x]);
        return par[x];
    }

    void unite(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sizes[x] < sizes[y]) swap(x, y);
        par[y] = x;
        sizes[x] += sizes[y];
    }

    bool same(int x,int y){ return find(x) == find(y); }
    int size(int x){ return sizes[find(x)]; }
};

int main(void){
    int N,K,L;
    cin>>N>>K>>L;
    UnionFind rail(N+1),road(N+1);
    rep(i,K){
        int p,q;
        cin>>p>>q;
        road.unite(p,q);
    }
    rep(i,L){
        int r,s;
        cin>>r>>s;
        rail.unite(r,s);
    }

    map<pair<int,int>,int> cnt;
    rep1(i,N){
        cnt[{road.find(i), rail.find(i)}]++;
    }
    rep1(i,N){
        cout<<cnt[{road.find(i), rail.find(i)}]<<(i==N ? "\n" : " ");
    }
    return 0;
}
