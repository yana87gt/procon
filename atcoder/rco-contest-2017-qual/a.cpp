#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define y first
#define x second
typedef pair<int,int> Point;
typedef pair<int,Point> Com;

int H,W,K;
int dy[4]={1,0,-1,0},dx[4]={0,1,0,-1};
int a[52][52]={};
stack<Point> res;

void make_piece(Com c){
	priority_queue<Com> next;
	next.push(c);
	while(next.size()){
		Point p=next.top().second;
		int y=p.y,x=p.x;
		next.pop();
		if(!a[y][x])continue;

		a[y][x]=0;
		res.push(p);
		if(res.size()%K==0)return;
		
		rep(i,4){
			int ny=y+dy[i],nx=x+dx[i];
			next.push({a[ny][nx],{ny,nx}});
		}
	}
}

int main(void){
	cin>>H>>W>>K;
	string s[H];
	rep(y,H)cin>>s[y];
	priority_queue<Com> start;
	rep1(y,H)rep1(x,W){
		a[y][x]=s[y-1][x-1]-'0';
		start.push({a[y][x],{y,x}});
	}

	while(start.size()){
		make_piece(start.top());
		start.pop();
		while(res.size()%K)res.pop();	
	}
	
	cout<<res.size()/K<<endl;
	while(res.size()){
		Point p=res.top();
		cout<<p.y<<" "<<p.x<<endl;
		res.pop();
	}
	return 0;
}
