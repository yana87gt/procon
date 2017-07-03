#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef complex<double> Point;
#define X real()
#define Y imag()

double dot(Point a, Point b) {
	return a.X*b.X + a.Y*b.Y;
}

Point proj(Point a1, Point a2, Point p) {
	return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

int main(void){
	double x1,y1,x2,y2,x,y;
	int q;
	cin>>x1>>y1>>x2>>y2>>q;
	rep(i,q){
		cin>>x>>y;
		Point p=proj({x1,y1},{x2,y2},{x,y});
		printf("%.9f %.9f\n",p.X,p.Y);
	}
	return 0;
}
