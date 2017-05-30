#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
	ll x,res;
	cin>>x;
	res = (x/11)*2;
	if(x%=11)res += x%11>6 ? 2 : 1;
	cout<<res<<endl;
	return 0;
}
