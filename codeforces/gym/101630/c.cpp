#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<int(n);i++)
#define all(s) s.begin(),s.end()
using namespace std;

vector<pair<int,int>> g[100005];
vector<pair<int,int>> rg[100005];

int a[100005], b[100005];

bool visited[100005];
bool used[100005];

void dfs(int v, vector<pair<int,int>> *G){
	visited[v] = true;
	for(auto to : G[v]) if(!visited[to.first]){
		used[to.second] = true;
		dfs(to.first, G);
	}
}

void solve(){
	int n,m;
	scanf("%d %d", &n, &m);
	rep(i,n) g[i].clear();
	rep(i,n) rg[i].clear();
	rep(i,m){
		scanf("%d %d", a+i, b+i);
		a[i]--; b[i]--;
		g[a[i]].push_back(make_pair(b[i], i));
		rg[b[i]].push_back(make_pair(a[i], i));
	}
	
	fill(used, used + m, false);
	
	fill(visited, visited+n, false);
	dfs(0, g);
	
	fill(visited, visited+n, false);
	dfs(0, rg);
	
	int cnt = 0;
	rep(i,m) if(used[i]) cnt++;
	for(int i=0; cnt < 2*n; i++) if(!used[i]){
		used[i] = true;
		cnt++;
	}
	
	rep(i,m) if(!used[i]){
		printf("%d %d\n", a[i]+1, b[i]+1);
	}
	
}

int main(){
	int n;
	cin>>n;
	rep(i,n) solve();
	
	return 0;
} 
