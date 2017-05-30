#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=n;++i)

int a[100001];
int main(void){
	int N,cnt=0;
	cin>>N;
	rep1(i,N)cin>>a[i];
	rep1(i,N)if(a[a[i]]==i)cnt++;
	cout<<cnt/2<<endl;
	return 0;
}
