#include <iostream>
#include <vector>
#include <algorithm>
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

	int unite(int x,int y){
		x = find(x);
		y = find(y);
		if(x == y) return sizes[x];
		if(sizes[x] < sizes[y]) swap(x, y);
		par[y] = x;
		return sizes[x] += sizes[y];
	}

	bool same(int x,int y){ return find(x) == find(y); }
	int size(int x){ return sizes[find(x)]; }
};

struct Edge{
	int a,b,cost;
	bool operator<(const Edge& right)const{
		return cost < right.cost;
	}
};

int main(void){
	int N,M;
	cin>>N>>M;
	vector<Edge> e(M);
	rep(i,M)cin>>e[i].a>>e[i].b>>e[i].cost;
	sort(e.begin(),e.end());
	UnionFind uf(N+1);
	rep(i,M){
		if(uf.unite(e[i].a,e[i].b)==N){
			cout<<e[i].cost<<endl;
			break;
		}
	}
	return 0;
}
