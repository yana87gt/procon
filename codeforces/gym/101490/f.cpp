#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) (a).begin(),(a).end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define ub(s,x) upper_bound(all(s),x)-s.begin()
#define uniq(a) a.erase(unique(all(a)),a.end())
#define debug(x) cout<<#x<<": "<<x<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
typedef long long ll;
const int INF = 1e9;


typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-8;
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

Point read_point(){
    double x,y;
    cin>>x>>y;
    return Point(x,y);
}

bool isecLP(Point a1, Point a2, Point b) {
    return abs(ccw(a1, a2, b)) != 1;
    // return EQ(cross(a2-a1, b-a1), 0); と等価
}

// 直線と直線
bool isecLL(Point a1, Point a2, Point b1, Point b2) {
    return !isecLP(a2-a1, b2-b1, 0) || isecLP(a1, b1, b2);
}

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
    double d1 = cross(b2-b1, b1-a1);
    double d2 = cross(b2-b1, a2-a1);
    if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
    assert(!EQ(d2, 0)); // 交点がない
    return a1 + d1/d2 * (a2-a1);
}

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
    return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

double distLP(Point a1, Point a2, Point p) {
    return abs(proj(a1, a2, p) - p);
}


VP l1,l2;

int which_line(Point p, int pre){
    int n = l1.size();
    rep(i,n)if(i != pre){
        if(distLP(l1[i],l2[i], p) < EPS){
            return i;
        }
    }
    assert(false);
}

bool is_dammy(Point p){
    return p == Point(-INF,-INF) || p == Point(+INF,+INF);
}

int main(void){
    int n,k;
    cin>>n>>k;
    Point start = read_point();
    vector<string> name(n);
    l1.resize(n);
    l2.resize(n);
    rep(i,n){
        cin>>name[i];
        l1[i] = read_point();
        l2[i] = read_point();
    }

    int sl = which_line(start, -1);

    vector<VP> cp(n);

    rep(i,n){
        rep(j,n)if(i!=j){
            if(isecLL(l1[i],l2[i], l1[j],l2[j])){
                cp[i].push_back(crosspointLL(l1[i],l2[i], l1[j],l2[j]));
            }
        }
        cp[i].push_back({-INF,-INF});
        cp[i].push_back({+INF,+INF});
        sort(all(cp[i]));
    }

    vector<string> result;
    Point pre = start,cur,nxt;
    int line = sl;
    rep(i, cp[sl].size() - 1){
        if(cp[sl][i] < start && start < cp[sl][i+1]){
            cur = cp[sl][i+1];
        }
    }

    if(is_dammy(cur)){
        cout<<name[line]<<endl;
        return 0;
    }

    do{
        result.push_back(name[line]);
        line = which_line(cur, line);
        for(int i = 1; i+1 < (int)cp[line].size(); i++){
            if(abs(cp[line][i] - cur) < EPS){
                VP nexts = {cp[line][i-1], cp[line][i+1]};
                bool ok[2] = {true, true};
                rep(j, nexts.size()){
                    if(is_dammy(nexts[j])){
                        ok[j] = false;
                    }
                    if(ccw(pre, cur, nexts[j]) != -1){
                        ok[j] = false;
                    }
                }
                if(!ok[0] && !ok[1]){
                    cout<<name[line]<<endl;
                    return 0;
                }
                nxt = ok[0] ? nexts[0] : nexts[1];
            }
        }
        pre = cur;
        cur = nxt;
    }while(name[line] != result[0]);

    int m = result.size();
    cout<<result[k%m]<<endl;

    return 0;
}
