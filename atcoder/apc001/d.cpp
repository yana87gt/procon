#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

struct UnionFind{
    vector<int> par;
    vector<int> sizes;
 
    UnionFind(){}
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

vector<priority_queue<ll,vector<ll>,greater<ll>>> pq;
priority_queue<pair<int,int>> choose;
UnionFind uf;

void merge(int x,int y){
    x = uf.find(x);
    y = uf.find(y);
    if(pq[x].size() < pq[y].size()){
        swap(x,y);
    }
    while(pq[y].size()){
        pq[x].push(pq[y].top());
        pq[y].pop();
    }
    uf.unite(x,y);
    int z = uf.find(x);
    // ufのルートに合わせる
    if(z != x){
        pq[z].swap(pq[x]);
    }
}

int main(void){
    int n,m;
    cin>>n>>m;
    pq.resize(n);
    uf = UnionFind(n);
    rep(i,n) {
        ll a;
        cin>>a;
        pq[i].push(a);
    }
    rep(_,m){
        int x,y;
        cin>>x>>y;
        merge(x,y);
    }

    rep(i,n){
        if(pq[i].size()){
            choose.push({pq[i].size(), i});
        }
    }

    ll res = 0;
    while(choose.size()>=2){
        int x = choose.top().second; choose.pop();
        int y = choose.top().second; choose.pop();
        if(pq[x].size()==0 || pq[y].size()==0){
            cout<<"Impossible"<<endl;
            return 0;   
        }
        res += pq[x].top() + pq[y].top();
        pq[x].pop(); pq[y].pop();
        merge(x,y);
        int z = uf.find(x);
        choose.push({pq[z].size(), z});
    }
    cout<<res<<endl;
    return 0;
}
