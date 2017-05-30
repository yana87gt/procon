#include <bits/stdc++.h>
using namespace std;

int solve3(int s1,int s2,int s3){
	int v[]={s1,s2,s3};
	sort(v,v+3);
	return v[2]-v[0];
}

int solve2(int a,int b,int s){
	int res=INT_MAX;
	res=min(res,solve3((a/2)*b,(a-a/2)*b,s));
	res=min(res,solve3(a*(b/2),a*(b-b/2),s));
	return res;
}

int solve(int a,int b){
	int a1=a/3,a2=a/3+1,b1=b/3,b2=b/3+1;
	int res=INT_MAX;
	res=min(res,solve2(a-a1,b,a1*b));
	res=min(res,solve2(a-a2,b,a2*b));
	res=min(res,solve2(a,b-b1,a*b1));
	res=min(res,solve2(a,b-b2,a*b2));
	return res;
}

int main(void){
	int H,W;
	cin>>H>>W;
	cout<<solve(H,W)<<endl;
	return 0;
}
