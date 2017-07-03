#include <bits/stdc++.h>
using namespace std;

int main(void){
	int a,b,c,d;
	int p1x,p1y,p2x,p2y;
	int p3x,p3y,p4x,p4y;
	double x,y;
	cin>>x>>y;
	if(x==0 && y==0){
		printf("1 0 -1 0\n0 1 0 -1\n");
		return 0;
	}
	bool fx=(x<0),fy=(y<0);
	x=round(fabs(x)*1000);
	y=round(fabs(y)*1000);
	a=(int)x/1000;
	b=(int)x%1000;
	c=(int)y/1000;
	d=(int)y%1000;
	// if(b==0){
	// 	p1x=a,p1y=c,p2x=a,p2y=c+1;
	// 	p3x=a-d,p3y=c,p4x=a+1000-d,p4y=c+1;
	// }else{
		p1x=a-b,p1y=c-d,p2x=a,p2y=c;
		p3x=a-b,p3y=c+1+(1000-d),p4x=a,p4y=c+1;
	// }
	if(fx)p1x*=-1,p2x*=-1,p3x*=-1,p4x*=-1;
	if(fy)p1y*=-1,p2y*=-1,p3y*=-1,p4y*=-1;

	printf("%d %d %d %d\n",p1x,p1y,p2x,p2y);
	printf("%d %d %d %d\n",p3x,p3y,p4x,p4y);
	return 0;
}
