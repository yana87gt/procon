#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
	cout<<100000<<endl;
	rep(i,50000){
		printf("1 %d 50000 %d\n",i,i);
	}
	rep(i,50000){
		int y1=rand()%500000000;
		int y2=rand()%500000000;
		if(y1==y2)y1++;
		printf("%d %d %d %d\n",i,y1,i,y2);	
	}
    return 0;
}
