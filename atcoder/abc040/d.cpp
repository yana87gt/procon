#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

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
    cin>>n>>m;
    using P = pair<pair<int, bool>,pair<int,int>>;
    vector<P> vp;
    rep(i,m){
        int a,b,y;
        cin>>a>>b>>y;
        a--,b--;
        vp.push_back({{y,0},{a,b}});
    }

    int q;
    cin>>q;
    rep(i,q){
        int v,y;
        cin>>v>>y;
        v--;
        vp.push_back({{y,1},{i,v}});
    }
    sort(all(vp), greater<P>());

    vector<int> res(q);
    UnionFind uf(n);
    rep(i,m+q){
        P p = vp[i];

        // People
        if (p.first.second) {
            int id = p.second.first;
            int v = p.second.second;
            res[id] = uf.size(v);
        }
        // Edge
        else {
            int a = p.second.first;
            int b = p.second.second;
            uf.unite(a, b);
        }
    }

    rep(i,q){
        cout << res[i] << endl;
    }
    return 0;
}
