#include <iostream>
using namespace std;
 
int main(void){
	int N,n,S=0;
	cin>>N;
	while(N--){
		cin>>n;
		S+=(S+n);
	}
	cout<<S<<endl;
	return 0;
}