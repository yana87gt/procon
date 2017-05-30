#include <bits/stdc++.h>
using namespace std;
#define all(s) (s).begin(),(s).end()
typedef pair<pair<int,int>,int> P;

int N,M,p,q,c;
vector<P> edge;//<<from,com>,to>
vector<int> dist;
vector<bool> visited;
queue<int> Q;//<from>

void solve(int from,int com){
	int left=lower_bound(all(edge),(P){{from,com},0})-edge.begin();
	int right=lower_bound(all(edge),(P){{from,com+1},0})-edge.begin();
	for(int i=left;i<right;i++){
		if(visited[i])continue;
		int to=edge[i].second;
		if(dist[to]>=dist[from]){
			dist[to]=dist[from];
			visited[i]=true;
			visited[lower_bound(all(edge),(P){{to,com},from})-edge.begin()]=true;
			solve(to,com);
		}
	}
	Q.push(from);
}

int main(void){
	cin>>N>>M;
	while(M--){
		cin>>p>>q>>c;
		edge.push_back({{p,c},q});
		edge.push_back({{q,c},p});
	}
	sort(all(edge));
	edge.erase(unique(all(edge)),edge.end());
	dist = vector<int>(N+1,INT_MAX);
	visited = vector<bool>(edge.size(),false);
	dist[1]=0;
	Q.push(1);

	while(!Q.empty()){
		int from=Q.front(); Q.pop();
		if(from==N)break;
		int left=lower_bound(all(edge),(P){{from,0},0})-edge.begin();
		int right=lower_bound(all(edge),(P){{from+1,0},0})-edge.begin();
		for(int i=left;i<right;i++){
			if(visited[i])continue;
			int com=edge[i].first.second;
			int to=edge[i].second;
			if(dist[to]>dist[from]+1){
				dist[to]=dist[from]+1;
				visited[i]=true;
				visited[lower_bound(all(edge),(P){{to,com},from})-edge.begin()]=true;
				solve(to,com);
			}
		}
	}
	cout<<(dist[N]==INT_MAX ? -1 : dist[N])<<endl;
	return 0;
}
