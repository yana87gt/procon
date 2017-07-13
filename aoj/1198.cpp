#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

VP c;
vector<double> r;
vector<VP> pg;
int N,M;

// rotation a->b [-pi,+pi]
double angle(Point a,Point b){
    double t = arg(b)-arg(a);
    while(t>+M_PI) t-=2*M_PI;
    while(t<-M_PI) t+=2*M_PI;
    return t;
}

bool inPolygon(Point p,VP& ps){
    int n = ps.size();
    double sumAngle=0;
    rep(i,n){
        sumAngle += angle(ps[i]-p, ps[(i+1)%n]-p);
    }
    return (abs(sumAngle) > 0.1);
}

bool notCross(Point p,Point q){
    bool inAnyCircle = false;
    rep(i,N){
        inAnyCircle |= abs(c[i]-p)<r[i];
        if((abs(c[i]-p)<r[i]) != (abs(c[i]-q)<r[i])) return false;
    }
    if(inAnyCircle) return true;
    
    rep(i,pg.size()){
        if(inPolygon(p,pg[i]) != inPolygon(q,pg[i])) return false;
    }
    return true;
}

int main(void){
    while(cin>>N>>M, N|M){
        c = VP(N);
        r = vector<double>(N);
        rep(i,N){
            double x,y;
            cin>>x>>y>>r[i];
            c[i] = {x,y};
        }

        vector<map<double,int>> G(N);
        rep(i,N)rep(j,i){
            double d = abs(c[i]-c[j]);
            if(r[i]+r[j]>=d && abs(r[i]-r[j])<d){
                G[i][arg(c[j]-c[i])] = j;
                G[j][arg(c[i]-c[j])] = i;
            }
        }
        
        pg.clear();
        rep(start,N){
            while(G[start].size()){
                int pre = start;
                int cur = (G[start].begin())->second;
                G[start].erase(G[start].begin());
                VP ps = {c[pre]};
                while(cur!=start){
                    ps.push_back(c[cur]);
                    auto itr = G[cur].upper_bound(arg(c[pre]-c[cur]));
                    if(itr==G[cur].end()) itr = G[cur].begin();
                    pre = cur;
                    cur = itr->second;
                    G[pre].erase(itr);
                }
                pg.push_back(ps);
            }
        }

        rep(i,M){
            double px,py,qx,qy;
            cin>>px>>py>>qx>>qy;
            cout<<(notCross(Point(px,py),Point(qx,qy)) ? "YES" : "NO");
            cout<<(i<M-1 ? " " : "\n");
        }
    }

    return 0;
}
