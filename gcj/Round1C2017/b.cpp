#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define DAY 1440
typedef pair<pair<int,int>,bool> Act;
#define head first.first
#define tail first.second
#define name second

int main(){
	int T;
	cin>>T;
	rep(_,T){
		int AC,AJ,h,t,sum[2]={},change=0;
		cin>>AC>>AJ;
		vector<Act> a(AC+AJ);
		rep(i,AC+AJ){
			cin>>h>>t;
			a[i]={{h,t},i<AC};
			sum[i<AC]+=t-h;
		}
		sort(a.begin(),a.end());
		a.push_back(a[0]);
		a[AC+AJ].head+=DAY;
		
		priority_queue<int> q[2];
		rep(i,AC+AJ){
			if(a[i].name != a[i+1].name) change++;
			else {
				int f=a[i+1].head-a[i].tail;
				q[a[i].name].push(f);
				sum[a[i].name]+=f;
			}
		}
		rep(k,2)while(sum[k]>DAY/2){
			sum[k]-=q[k].top();
			q[k].pop();
			change+=2;
		}
		printf("Case #%d: %d\n",_+1,change);
	}
	return 0;
}
