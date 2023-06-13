// -------- START : snippet -------- //

#include <bits/stdc++.h>
using namespace std;

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

// -------- START : macro -------- //

#define ll long long
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)
#define rep1(i,n) for(long long i = 1; i <= (long long)(n); ++i)
#define len(c) (ll)c.size()
#define all(v) (v).begin(),(v).end()
#define lb(v,x) (lower_bound(all(v),x)-v.begin())
#define ub(v,x) (upper_bound(all(v),x)-v.begin())
#define has(c,x) (c.find(x) != c.end())
#define uniq(v) v.erase(unique(all(v)),v.end())
#define bit(k) (1LL<<(k))
#define INF int(1e9)

template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

// -------- END : macro -------- //

// -------- START : debug macro -------- //

template<class T,class U> ostream& operator<<(ostream& ost, const pair<T,U> &p) { ost << "(" << p.first << ", " << p.second << ")"; return ost; }
#define ostream_container { ost << "{"; for(const auto &t : v) { if (&t != &*v.begin()) ost << ", "; ost << t; } ost << "}"; return ost; }
template<class T> ostream& operator<<(ostream &ost, const vector<T> &v) ostream_container
template<class T> ostream& operator<<(ostream &ost, const set<T> &v) ostream_container
template<class T,class U> ostream& operator<<(ostream &ost, const map<T,U> &v) ostream_container

template<class H> void recursive_debug(string s, H h) {
    cerr << "\033[33m" << s << " = " << h << endl << "\033[m";
}
template<class H,class... T> void recursive_debug(string s, H h, T... t) {
    int comma = s.find(',');
    cerr << "\033[33m" << s.substr(0,comma) << " = " << h << ", ";
    recursive_debug(s.substr(comma+1), t...);
}
#define debug(...) recursive_debug(#__VA_ARGS__, __VA_ARGS__)

// -------- END : debug macro -------- //

// -------- END : snippet -------- //

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

double distCC(Point a, double ar, Point b, double br) {
    double d = abs(a-b);
    return GE(d, abs(ar-br)) ? max(d-ar-br, 0.0) : abs(ar-br) - d;
}

struct UnionFind{
    vector<int> par;
    vector<int> sizes;
    UnionFind(int n):par(n),sizes(n,1){ rep(i,n)par[i]=i; }

    //find root of x
    int find(int x){
        if(x!=par[x]) par[x] = find(par[x]);
        return par[x];
    }

    void unite(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sizes[x] < sizes[y]) swap(x, y);
        par[y] = x;
        sizes[x] += sizes[y];
    }

    bool same(int x,int y){ return find(x) == find(y); }
    int size(int x){ return sizes[find(x)]; }
};

double dPP[50][50];
double dCC[8][8];
double dPC[50][8];

int main(void) {
    int N, M;
    cin >> N >> M;
    VP p(N), c(M);
    vector<double> r(M);
    rep(i,N){
        double x,y;
        cin >> x >> y;
        p[i] = Point(x,y);
    }
    rep(i,M){
        double x,y;
        cin >> x >> y >> r[i];
        c[i] = Point(x,y);
    }

    rep(i,N)rep(j,i) dPP[i][j] = dPP[j][i] = abs(p[i] - p[j]);
    rep(i,M)rep(j,i) dCC[i][j] = dCC[j][i] = distCC(c[i],r[i], c[j],r[j]);
    rep(i,N)rep(j,M) dPC[i][j] = abs(r[j] - abs(p[i] - c[j]));

    double res = 1e9;
    rep(mask, 1<<M) {
        UnionFind uf(N+M);
        using P = pair<double, pair<int,int>>;
        priority_queue<P, vector<P>, greater<P>> qu;
        rep(i,N)rep(j,i) {
            qu.push({dPP[i][j], {i, j}});
        }
        rep(i,N)rep(j,M) {
            if (mask & bit(j)) {
                qu.push({dPC[i][j], {i, N+j}});
            }
        }
        rep(i,M)rep(j,i) {
            if(mask & bit(i)) if(mask & bit(j)) {
                qu.push({dCC[i][j], {N+i, N+j}});
            }
        }

        double dist_sum = 0;
        while(qu.size()) {
            P top = qu.top();
            qu.pop();
            double d = top.first;
            int u = top.second.first;
            int v = top.second.second;
            if (uf.same(u, v)) continue;
            uf.unite(u, v);
            dist_sum += d;
        }
        chmin(res, dist_sum);
    }
    cout << res << endl;
    return 0;
}
