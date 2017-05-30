#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;

int a[102][102]={};
int b[102][102]={};
int c[102][102]={};
int dx[]={-1,-1,-1,0,0 ,0, 1,1,1};
int dy[]={-1, 1, 0,1,-1,0,-1,0,1};

int main(void){
	int H,W;
	char ch;

	cin>>H>>W;

	rep1(y,H)rep1(x,W){
		cin>>ch;
		if(ch=='.')a[y][x]=1;
	}

	rep1(y,H)rep1(x,W){
		bool sharp=true;
		rep(i,9){
			if(a[y+dy[i]][x+dx[i]]==1){
				sharp=false;
				break;
			}
		}
		if(sharp)b[y][x]=1;
	}

	rep1(y,H)rep1(x,W){
		if(b[y][x])rep(i,9)c[y+dy[i]][x+dx[i]]=1;
	}

	bool impossible=false;
	rep1(y,H)rep1(x,W){
		if(a[y][x]+c[y][x]!=1)impossible=true;
	}

	if(impossible){
		cout<<"impossible"<<endl;
	}else{
		cout<<"possible"<<endl;
		rep1(y,H){
			rep1(x,W){
				cout<<(b[y][x]==1 ? '#' : '.');
			}
			cout<<endl;
		}
	}

	return 0;
}
