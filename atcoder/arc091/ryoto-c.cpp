#include <iostream>
#include <algorithm>
#include <vector>
 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
int main(int argc, char* argv[]) {
	int n,k;
	scanf("%d %d",&n,&k);
	int i, c=0, tmp;
	for (i=k+1;i<=n;i++) {
		c+=(i-k)*(n/i);
		tmp = n%i;
		if (tmp >= k) {
			c+=(k==0)?tmp-k:tmp-k+1;
		}
	}
	printf("%d\n",c);
	return 0;
}
