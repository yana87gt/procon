#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

// 点aと点bを通り、半径がrの円の中心を返す
VP circlesPointsRadius(Point a, Point b, double r) {
  VP cs;
  Point abH = (b-a)*0.5;
  double d = abs(abH);
  if (d == 0 || d > r) return cs;
  double dN = sqrt(r*r - d*d);
  Point n = abH * Point(0,1) * (dN / d);
  cs.push_back(a + abH + n);
  if (dN > 0) cs.push_back(a + abH - n);
  return cs;
}

int main(void){
    int N;
    while(cin>>N,N){
        VP p(N);
        int res=1;
        rep(i,N){
            double x,y;
            cin>>x>>y;
            p[i] = {x,y};
        }
        rep(i,N)rep(j,i){
            VP cs = circlesPointsRadius(p[i],p[j],1.0);
            for(Point c:cs){
                int cnt=0;
                rep(k,N) if(abs(c-p[k]) <= 1.0001)cnt++;
                res=max(res,cnt);
            }
        }
        cout<<res<<endl;
    }

    return 0;
}
