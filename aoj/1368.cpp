#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int t[10][10],a[5];

int check(int k){
	if(k==0)return t[0][a[k]];
	return t[check(k-1)][a[k]];
}

int main(void){
	int cnt=0;
	rep(i,10)rep(j,10)cin>>t[i][j];
	rep(n,10000){
		bool flag=false;
		int d=1000;
		a[0]=n;
		rep(k,4){
			a[k+1]=a[k]%d;
			a[k]/=d;
			d/=10;
		}
		a[4]=check(3);

		/* Altering one single digit */
		rep(k,5){
			int tmp=a[k];
			rep(i,10){
				if(i==tmp)continue;
				a[k]=i;
				if(check(4)==0)flag=true;
			}
			a[k]=tmp;
		}

		/* Transposing two adjacent digits */
		rep(k,4){
			if(a[k]==a[k+1])continue;
			swap(a[k],a[k+1]);
			if(check(4)==0)flag=true;
			swap(a[k],a[k+1]);
		}

		if(flag)cnt++;
	}
	cout<<cnt<<endl;

	return 0;
}
