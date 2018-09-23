#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-8;

int main(void){
    int n;
    while(cin>>n, n){
        VP p(n);
        vector<double> r(n);
        vector<int> c(n);
        rep(i,n){
            double x,y;
            cin>>x>>y>>r[i]>>c[i];
            p[i] = Point(x,y);
        }

        int cnt = 0;
        vector<bool> is_front(n), selected(n);
        while(1){
            bool remove = false;
            rep(i,n){
                if(selected[i]) continue;
                bool ok = true;
                rep(j,i)if(!selected[j]){
                    if(r[i]+r[j] > abs(p[i]-p[j])){
                        ok = false;
                    }
                }
                if(ok) is_front[i] = true;
            }
            rep(i,n)rep(j,i)if(!selected[i] && !selected[j]){
                if(is_front[i] && is_front[j] && c[i]==c[j]){
                    selected[i] = selected[j] = true;
                    cnt += 2;
                    remove = true;
                }
            }

            if(!remove) break;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
