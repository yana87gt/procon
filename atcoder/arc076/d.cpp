#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) a.begin(),a.end()
typedef long long ll;
struct Point{ int x,y,id; };
struct edge{ int from,to,cost; };
bool compe(edge &e1,edge &e2){ return e1.cost<e2.cost; }
bool compx(Point &p1,Point &p2){ return p1.x<p2.x; }
bool compy(Point &p1,Point &p2){ return p1.y<p2.y; }

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
    int N;
    cin>>N;
    vector<Point> p(N);
    rep(i,N){
        cin>>p[i].x>>p[i].y;
        p[i].id=i;
    }

    vector<edge> ve;
    
    sort(all(p),compx);
    rep(i,N-1){
        ve.push_back({p[i].id, p[i+1].id, p[i+1].x-p[i].x});
    }
    
    sort(all(p),compy);
    rep(i,N-1){
        ve.push_back({p[i].id, p[i+1].id, p[i+1].y-p[i].y});
    }
    

    UnionFind uf(N);
    sort(all(ve),compe);
    ll res=0;
    rep(i,(int)ve.size()){
        if(!uf.same(ve[i].from,ve[i].to)){
            uf.unite(ve[i].from,ve[i].to);
            res+=ve[i].cost;
        }
    }
    cout<<res<<endl;
    return 0;
}
