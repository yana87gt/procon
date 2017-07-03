#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

vector<pair<int,pair<int,int> > > edge;

struct UnionFind{
    vector<int> par;
    vector<int> sizes;
    UnionFind(int n):par(n),sizes(n,1){ rep(i,n)par[i]=i; }

    //find root of x
    int find(int x){
        if(x!=par[x]) par[x] = find(par[x]);
        return par[x];
    }

    bool unite(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(sizes[x] < sizes[y]) swap(x, y);
        par[y] = x;
        sizes[x] += sizes[y];
        return true;
    }

    bool same(int x,int y){ return find(x) == find(y); }
    int size(int x){ return sizes[find(x)]; }
};

int main(void){
    int N,c;
    while(cin>>N){
        UnionFind uf(N);
        edge.clear();
        int cost=0;
        rep(i,N)rep(j,N){
            cin>>c;
            edge.push_back({c,{i,j}});
        }
        sort(edge.begin(),edge.end());
        rep(i,edge.size()){
            if(uf.unite(edge[i].second.first,edge[i].second.second)){
                cost+=edge[i].first;
            }
        }
        cout<<cost<<endl;
    }

    return 0;
}
