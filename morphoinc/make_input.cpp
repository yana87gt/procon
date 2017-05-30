#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
typedef long long ll;

#define MAX_SIZE 1000000
int main(void){
	int N=MAX_SIZE;
	cout<<N<<endl;
	srand(time(NULL));
	rep1(i,N)cout<<rand()%MAX_SIZE +1<<(i==N ? "\n" : " ");
	return 0;
}
