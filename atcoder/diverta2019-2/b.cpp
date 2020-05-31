#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

typedef complex<ll> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

namespace std {
    bool operator<(const Point a, const Point b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

int main(void){
    int n;
    cin >> n;
    VP ps(n);
    rep(i,n){
        ll x, y;
        cin >> x >> y;
        ps[i] = Point(x,y);
    }
    sort(all(ps));
    int res = n;
    rep(i,n)rep(j,i){
        ll dx = ps[i].X - ps[j].X;
        ll dy = ps[i].Y - ps[j].Y;
        int cost = n;
        rep(k,n){
            if (find(all(ps), Point(ps[k].X + dx, ps[k].Y + dy)) != ps.end()){
                cost--;
            }
        }
        res = min(res, cost);
    }
    cout << res << endl;
    return 0;
}
