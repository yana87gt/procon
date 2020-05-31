#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef complex<ll> Point;
#define X real()
#define Y imag()

void solve(){
    ll gx,gy;
    cin >> gx >> gy;
    if (abs(gx + gy) % 2 == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    Point g(gx,gy);
    Point e[] = {{0,-1}, {1,0}, {0,1}, {-1,0}};
    string c = "SENW";
    rep(max_r,31){
        string command = "";
        Point p(0,0);
        for(int r = max_r; r >= 0; r--) {
            int ii = 0;
            double min_dist = 1e15;
            rep(i,4){
                Point nxt = p + e[i]*bit(r);
                double dist = abs(complex<double>((nxt-g).X, (nxt-g).Y));
                if (min_dist > dist) {
                    min_dist = dist;
                    ii = i;
                }
            }
            command += c[ii];
            p += bit(r) * e[ii];
        }
        if (p == g) {
            reverse(all(command));
            cout << command << endl;
            return;
        }
    }
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        solve();
    }
    return 0;
}
