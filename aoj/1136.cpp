#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()

typedef complex<int> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

string line2str(VP ps){
    string s;
    int m = ps.size();
    rep(j,m-2){
        int d = abs(ps[j+1]-ps[j]);
        bool ccw = (cross(ps[j+1]-ps[j],ps[j+2]-ps[j]) > 0);
        s += to_string(d)+(ccw?"L":"R");
    }
    s += to_string((int)abs(ps[m-1]-ps[m-2]));
    return s;
}

int main(void){
    int n;
    while(cin>>n, n){
        vector<VP> ls(n+1);
        rep(i,n+1){
            int m;
            cin>>m;
            ls[i] = VP(m);
            rep(j,m){
                int x,y;
                cin>>x>>y;
                ls[i][j] = {x,y};
            }
        }

        string key1 = line2str(ls[0]);
        reverse(all(ls[0]));
        string key2 = line2str(ls[0]);
        rep1(i,n) {
            string s = line2str(ls[i]);
            if(s==key1 || s==key2) cout<<i<<endl;
        }
        cout<<"+++++"<<endl;
    }
    return 0;
}
