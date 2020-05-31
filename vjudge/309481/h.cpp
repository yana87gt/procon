#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define lb(s,x) (lower_bound(all(s),x)-s.begin())
#define ub(s,x) (upper_bound(all(s),x)-s.begin())
#define uniq(a) a.erase(unique(all(a)),a.end())
#define bit(k) (1LL<<(k))
const int INF = 1e9;
const double PI = acos(-1);

#define debug(x) cerr<<(#x)<<": "<<(x)<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-9;
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define ps_edge(PS,i) PS[i],PS[(i+1)%PS.size()]

namespace std {
    bool operator<(const Point &a, const Point &b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

double dot(const Point &a, const Point &b) {
    return a.X*b.X + a.Y*b.Y;
}

double cross(const Point &a, const Point &b) {
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

// 線分と線分
bool isecSS(const Point &a1, const Point &a2, const Point &b1, const Point &b2) {
    return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
           ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// 線分と点
bool isecSP(const Point &a1, const Point &a2, const Point &b) {
    return !ccw(a1, a2, b);
}

// 多角形の内部判定
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inPolygon(const VP& ps, const Point &p) {
    int n = ps.size();
    bool in = false;
    rep (i, n) {
        Point a = ps[i] - p;
        Point b = ps[(i + 1) % n] - p;
        if (EQ(cross(a,b), 0) && LE(dot(a,b), 0)) return 2;
        if (a.Y > b.Y) swap(a,b);
        if ((a.Y*b.Y < 0 || (a.Y*b.Y < EPS && b.Y > EPS)) && LE(cross(a, b), 0)) in = !in;
    }
    return in;
}

// 多角形の符号付面積
double area(const VP& ps) {
    double a = 0;
    rep (i, ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
    return a / 2;
}

bool can[810][810] = {};

int main(void){
    int n;
    cin >> n;
    VP ps(n);
    rep(i,n){
        int x,y;
        scanf("%d %d", &x, &y);
        ps[i] = Point(x,y);
    }

    bool rev = false;
    if (area(ps) < 0) {
        reverse(all(ps));
        rev = true;
    }
    Point sg[2];
    rep(i,2){
        int x,y;
        scanf("%d %d", &x, &y);
        sg[i] = Point(x,y);
    }
    rep(i,n)rep(j,n){
        can[i][j] = can[j][i] = (i != j);
    }
    rep(i,n){
        Point pl = ps[(i+n-1)%n];
        Point pr = ps[(i+1)%n];
        Point last = pr;
        bool hidden = false;

        for (int j = i+2; (j+1)%n != i; ++j) {
            if (hidden && ccw(ps[j%n], ps[i], last) == 1) {
                hidden = false;
                last = pr;
            } else if (
                j > i+2 && !hidden
                && ccw(ps[(j-2)%n], ps[(j-1)%n], ps[j%n]) == -1
                && ccw(ps[(j-1)%n], ps[i], ps[j%n]) > 0)
            {
                // hidden
                can[i][j%n] = can[j%n][i] = false;
                last = ps[(j-1)%n];
                hidden = true;
            }
            if (!(ccw(last, ps[i], ps[j%n]) == -1 && ccw(ps[j%n], ps[i], pl) == -1)) {
                can[i][j%n] = can[j%n][i] = false;
            }
            if (isecSS(ps[i], ps[j%n], sg[0], sg[1])) {
                can[i][j%n] = can[j%n][i] = false;
            }
        }
        // last = pl;
        // hidden = false;
        // for (int j = i+n-2; (j-1)%n != i; --j) {
        //     if (hidden && ccw(ps[j%n], ps[i], last) == 1) {
        //         hidden = false;
        //         last = pl;
        //     } else if (
        //         !hidden && ccw(ps[(j-2)%n], ps[(j-1)%n], ps[j%n]) == 1
        //         && ccw(ps[(j-1)%n], ps[i], ps[j%n]) != 1)
        //     {
        //         // hidden
        //         can[i][j%n] = can[j%n][i] = false;
        //         last = ps[(j-1)%n];
        //         hidden = true;
        //     }

        //     if (!(ccw(pr, ps[i], ps[j%n]) == -1 && ccw(ps[j%n], ps[i], last) == -1)) {
        //         can[i][j%n] = can[j%n][i] = false;
        //     }
        // }
    }

    rep(a,n)rep(b,a){
        // ps[a] -- ps[b] は多角形の辺ではないものとする
        if (a-b == 1 || (a==n-1 && b==0)) continue;

        if (isecSS(ps[a], ps[b], sg[0], sg[1])) {
            can[a][b] = can[b][a] = false;
            continue;
        }

        rep(i,n){
            // ps[a] -- ps[b] が多角形の辺と交差(端点を共有しているときを含まない)
            if (i != a && (i+1)%n != a && i != b && (i+1)%n != b
                && isecSS(ps[i], ps[(i+1)%n], ps[a], ps[b]))
            {
                can[a][b] = can[b][a] = false;
                break;
            }
        }
        if (!can[a][b]) continue;

        int cnt = 0;
        rep(i,n){
            if (isecSP(ps[a], ps[b], ps[i])) cnt++;
        }
        // 多角形の頂点のうち ps[a] -- ps[b] 上のものは2だけ
        if (cnt != 2) {
            can[a][b] = can[b][a] = false;
            continue;
        }

        // ps[a] -- ps[b] の中点が多角形の内部にない
        if (inPolygon(ps, (ps[a] + ps[b])/2.0) != 1) {
            can[a][b] = can[b][a] = false;
        }
    }

    rep(a,n)rep(b,a)rep(c,b){
        // ps[a], ps[b], ps[c] の三角形でsgを囲える
        if (!can[a][b] || !can[b][c] || !can[c][a]) continue;
        VP tri = {ps[a], ps[b], ps[c]};
        if (inPolygon(tri, sg[0]) == 1 && inPolygon(tri, sg[1]) == 1) {
            if (!rev) printf("%d %d %d\n", c+1, b+1, a+1);
            else printf("%d %d %d\n", n-a, n-b, n-c);
            return 0;
        }
    }
    printf("Impossible\n");
    return 0;
}
