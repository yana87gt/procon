#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N,A=0;
	bool judge=true;
	string s;
	cin>>N;
	while(N--)
	{
		cin>>s;
		if(s=="A")A++;
		else if(A)A--;
		else judge=false;
	}

	cout<<(judge && A==0 ? "YES" : "NO")<<endl;

	return 0;
}
