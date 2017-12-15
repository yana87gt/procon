#include <iostream>
using namespace std;

int main ()
{
	int n;
	cin>>n;
	int res=1;
	do
	{
		res *= n;
		n--;
	} while (n>0);
	cout<<res<<endl;
	return 0;
}

