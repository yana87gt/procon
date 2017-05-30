#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
struct Point{double x,y;};
bool comp(Point a,Point b) {return (a.x==b.x ? a.y<b.y : a.x<b.x);}

int main(void){
	string s;
	int alpha[26]={};
	bool judge=false;
	cin>>s;
	rep(i,s.length()) alpha[s[i]-'a']++;
	rep(i,26) judge |= alpha[i] % 2;
	cout<< (judge ? "No" : "Yes") << endl;

	return 0;
}
