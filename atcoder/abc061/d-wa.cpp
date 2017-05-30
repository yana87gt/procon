#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
typedef long long ll;
#define N_MAX 1001
#define M_MAX 2001
vector<int> G[N_MAX];
int v[M_MAX];
int a[M_MAX];
int b[M_MAX];
ll c[M_MAX];
ll dist[N_MAX];

int main(void){
	int N,M;
	cin>>N>>M;
	rep1(i,M){
		cin>>a[i]>>b[i]>>c[i];
		G[a[i]].push_back(i);
	}
	queue<int> qu;
	qu.push(1);
	while(qu.size()){
		int now=qu.front();
		qu.pop();
		for(int i:G[now]){
			if(v[i]==0 || dist[a[i]]+c[i]>dist[b[i]]){
				dist[b[i]]=dist[a[i]]+c[i];
				qu.push(b[i]);
				v[i]++;
			}
		}
		if(qu.size()>100000){
			while(qu.size()){
				int q=qu.front();
				qu.pop();
				if(b[q]==N)cout<<"inf"<<endl;
			}
		}
	}
	cout<<dist[N]<<endl;
	return 0;
}
