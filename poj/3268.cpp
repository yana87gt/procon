#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
typedef pair<int,int> P;

struct Edge{
	int to,weight,dir;
};
struct Node{
	vector<Edge> edge;
	int cost[2];
};
int N,M,X,A,B,T;
vector<Node> node;

void dijkstra(int dir){
	rep1(i,N)node[i].cost[dir]=INT_MAX;
	node[X].cost[dir]=0;
	priority_queue< P,vector<P>,greater<P> > Q;
	Q.push({0,X});
	while(!Q.empty()){
		P p=Q.top(); Q.pop();
		int cost1=p.first,n=p.second;
		if(cost1 > node[n].cost[dir]) continue;
		rep(i,node[n].edge.size()){
			Edge e = node[n].edge[i];
			if(e.dir != dir)continue;
			int cost2 = cost1+e.weight;
			if(node[e.to].cost[dir] > cost2){
				node[e.to].cost[dir] = cost2;
				Q.push({cost2,e.to});
			}
		}
	}
}

int main(void){
	cin>>N>>M>>X;
	node.resize(N+1);
	rep(_,M){
		cin>>A>>B>>T;
		node[A].edge.push_back({B,T,0});
		node[B].edge.push_back({A,T,1});
	}
	dijkstra(0);
	dijkstra(1);
	int res = 0;
	rep1(i,N) res = max(res,node[i].cost[0]+node[i].cost[1]);
	cout<<res<<endl;
	return 0;
}
