#include <bits/stdc++.h>
#define INF 4000001
using namespace std;
int n,m;
struct edge{int to,co;};
vector<edge> g[100010];
int dis[100010];
set<int> disc[100010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
 
	dis[1]=0;
	for(int i=2;i<=n;i++)
		dis[i]=INF;
	priority_queue<pair<int,int>> q;
	q.push({-dis[1],1});
	while(q.size())
	{
		int now=q.top().second;
		int d=-q.top().first;
		q.pop();
		if(dis[now]<d) continue;
		for(edge j:g[now])
		{
			//cout<<j.to<<endl;
			int nd=dis[now];
			if(!disc[now].count(j.co)) nd++;
			if(nd<dis[j.to])
			{
				dis[j.to]=nd;
				disc[j.to].clear();
				disc[j.to].insert(j.co);
				q.push({-dis[j.to],j.to});
			}
			else if(nd==dis[j.to])
			{
				disc[j.to].insert(j.co);
			}
		}
	}
	if(dis[n]==INF)
		cout<<-1<<endl;
	else
		cout<<dis[n]<<endl;
}