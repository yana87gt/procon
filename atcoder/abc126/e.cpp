#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

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
    int n,m;
    cin >> n >> m;
    UnionFind uf(n);
    rep(i,m){
        int x,y,z;
        cin >> x >> y >> z;
        x--,y--;
        uf.unite(x,y);
    }
    set<int> roots;
    rep(i,n){
        roots.insert(uf.find(i));
    }
    cout << roots.size() << endl;
    return 0;
}
