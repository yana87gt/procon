#include <iostream>
using namespace std;
int main(void){
	long long N,P=2,a,cnt;
	cin>>N>>a;
	cnt=a-1;
	while(--N){
		cin>>a;
		if(P==a)P++;
		else cnt+=(a-1)/P;
	}
	cout<<cnt<<endl;
	return 0;
}
