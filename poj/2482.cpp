#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstdlib>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin();
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
struct Point{
	double x,y;
	bool operator<(const Point& right)const{
		return (x==right.x ? y<right.y : x<right.x);
	}
};
bool comp(Point a,Point b) {return (a.x==b.x ? a.y<b.y : a.x<b.x);}

int main(void){
	int N;

	return 0;
}
