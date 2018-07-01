#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

struct C{ double x,y,z,r; };

double abs(C a,C b){
    double d = sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
    return max(d-(a.r+b.r),0.0);
}

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
    int n;
    while(cin>>n, n){
        vector<C> cs(n);
        rep(i,n){
            double x,y,z,r;
            cin>>x>>y>>z>>r;
            cs[i] = {x,y,z,r};
        }

        using P = pair<double,pair<int,int>>;
        priority_queue<P,vector<P>,greater<P>> pq;
        rep(i,n)rep(j,i) {
            pq.push({abs(cs[i],cs[j]), {i,j}});
        }
        UnionFind uf(n);
        double cost = 0;
        while(pq.size()){
            P p = pq.top(); pq.pop();
            double d = p.first;
            int a = p.second.first;
            int b = p.second.second;
            if(!uf.same(a,b)){
                uf.unite(a,b);
                cost += d;
            }
        }
        printf("%.3f\n",cost);
    }
    return 0;
}
