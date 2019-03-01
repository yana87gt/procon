#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
#define debug(x) cerr<<(#x)<<": "<<(x)<<endl
typedef long long ll;

typedef complex<ll> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 0;

namespace std {
    bool operator<(const Point a, const Point b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

double dot(Point a, Point b) {
    return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b) {
    return a.X*b.Y - a.Y*b.X;
}

int ccw(Point a, Point b, Point c) {
    b -= a;  c -= a;
    if (cross(b,c) >  EPS) return +1;  // counter clockwise
    if (cross(b,c) < -EPS) return -1;  // clockwise
    if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
    if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
    return 0;                          // a--c--b on line or a==c or b==c
}

// 線分と点
bool isecSP(Point a1, Point a2, Point b) {
    return !ccw(a1, a2, b);
}

VP convexHull(VP ps) {  // 元の点集合がソートされていいならVP&に
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end());
    VP ch(2*n);
    for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
        while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;  // 余計な点も含むなら == -1 とする
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
        while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    ch.resize(k-1);
    return ch;
}

// 凸多角形の内部判定　O(n)
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inConvex(Point p, const VP& ps) {
    int n = ps.size();
    int dir = ccw(ps[0], ps[1], p);
    rep (i, n) {
        int ccwc = ccw(ps[i], ps[(i + 1) % n], p);
        if (!ccwc) return 2;  // 線分上に存在
        if (ccwc != dir) return 0;
    }
    return 1;
}

bool check(VP &ps, VP &ch, int m, int mask){
    vector<pair<Point,Point>> edges;
    rep(i,m){
        if(mask & (1<<i)){
            edges.push_back({ch[i], ch[(i+1)%m]});
        }
    }

    VP line;
    rep(i,ps.size()){
        bool on = false;
        rep(j,2){
            if (isecSP(edges[j].first, edges[j].second, ps[i])) {
                on = true;
            }
        }
        if (!on) {
            line.push_back(ps[i]);
        }
    }
    if (line.size() <= 1) return true;
    sort(all(line));
    // edges.push_back({line})

    int don_cnt = 0;
    rep(i,3){
        if (cross(edges[i].first - edges[i].second, edges[(i+1)%m].first - edges[(i+1)%m].second) == 0) {
            return false;
        }
        if (dot(edges[i].first - edges[i].second, edges[(i+1)%m].second - edges[(i+1)%m].first) < 0) {
            don_cnt++;
        }
    }
    if (don_cnt > 1) return false;
    
    return true;
}

bool solve(int n){
    vector<Point> ps(n);
    rep(i,n) {
        ll x,y;
        cin >> x >> y;
        ps[i] = {x,y};
    }
    VP ch = convexHull(ps);
    int m = ch.size();
    debug(m);
    if (m > 6) return false;
    if (m <= 3) return true;
    rep(i,n) {
        if (inConvex(ps[i], ch) == 1) return false; 
    }

    rep(mask, 1<<m){
        if(__builtin_popcount(mask) == 2){
            if (check(ps,ch,m,mask)) return true;
        }
    }
    return false;
}

int main(void){
    int n;
    while(cin >> n, n) {
        cout << ((solve(n)) ? "YES" : "NO") << endl;
    }
    return 0;
}
