#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) a.begin(),a.end()
struct Point{int x,y,id;};
bool linkx(Point &p1,Point &p2){ return p1.y==p2.y ? p1.x<p2.x : p1.y<p2.y; }
bool linky(Point &p1,Point &p2){ return p1.x==p2.x ? p1.y<p2.y : p1.x<p2.x; }
int xid(Point &p){return p.id*2;}
int yid(Point &p){return p.id*2+1;}

#define MAX_V 400010
#define INF 1e18
typedef long long ll;
struct edge{ll cost; int to;};
typedef pair<ll,int> P;//dp[v],v

vector<Point> vp;
vector<edge> G[MAX_V]; 
ll dp[MAX_V];
int M,N,K,X,Y;

ll dijkstra(){
	fill(dp,dp+MAX_V,INF);
	priority_queue<P,vector<P>,greater<P>> qu;
	if(vp[0].x==1){
		dp[yid(vp[0])]=vp[0].y-1;
		qu.push({dp[yid(vp[0])],yid(vp[0])});
	}
	while(qu.size()){
		P pr=qu.top(); qu.pop();
		int v=pr.second;
		if(v>=2*K)return pr.first;
		if(dp[v] < pr.first)continue;
		for(edge e:G[v]){
			if( dp[e.to] > dp[v]+e.cost){
				dp[e.to] = dp[v]+e.cost;
				qu.push({dp[e.to],e.to});
			}
		}
	}
	return -1;
}


int main(void){
	cin>>M>>N>>K;
	rep(i,K){
		cin>>X>>Y;
		vp.push_back({X,Y,i});
	}
	vp.push_back({M,N,K});

	//switch
	rep(i,K){
		G[xid(vp[i])].push_back({1,yid(vp[i])});
		G[yid(vp[i])].push_back({1,xid(vp[i])});
	}

	//linkx
	sort(all(vp),linkx);
	rep(i,K){
		if(vp[i].y==vp[i+1].y){
			Point p1=vp[i],p2=vp[i+1];
			int cost=abs(p1.x-p2.x);
			G[xid(p1)].push_back({cost,xid(p2)});
			G[xid(p2)].push_back({cost,xid(p1)});
		}
	}

	//linky
	sort(all(vp),linky);
	rep(i,K){
		if(vp[i].x==vp[i+1].x){
			Point p1=vp[i],p2=vp[i+1];
			int cost=abs(p1.y-p2.y);
			G[yid(p1)].push_back({cost,yid(p2)});
			G[yid(p2)].push_back({cost,yid(p1)});
		}
	}
	cout<<dijkstra()<<endl;
	return 0;
}
