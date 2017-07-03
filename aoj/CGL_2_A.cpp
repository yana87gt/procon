#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef complex<double> Point;
#define X real()
#define Y imag()
const double EPS = 1e-9;
#define EQ(n,m) (abs((n)-(m)) < EPS)

double dot(Point a, Point b) {
	return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b) {
	return a.X*b.Y - a.Y*b.X;
}

int crossform(Point p0,Point p1,Point p2,Point p3){
	if(EQ(cross(p0-p1,p2-p3),0))return 2; //Parallel
	if(EQ(dot(p0-p1,p2-p3),0))return 1; //Orthogonal
	return 0;
}

int main(void){
	int q;
	cin>>q;
	rep(i,q){
		double x0,y0,x1,y1,x2,y2,x3,y3;
		cin>>x0>>y0>>x1>>y1>>x2>>y2>>x3>>y3;
		cout<<crossform({x0,y0},{x1,y1},{x2,y2},{x3,y3})<<endl;
	}
	return 0;
}
