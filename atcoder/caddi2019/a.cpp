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

#define debug(x) cerr<<(#x)<<": "<<(x)<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

class Ball{
  public:
    Ball() {}
    Ball(int id_, double r_, ll point_):
        id(id_), r(r_), point(point_) {}

    ~Ball() {}
    int id;
    double r;
    ll point;
};


vector<ll> score;

bool comp_point(Ball a, Ball b) {
    return (a.point == b.point ? a.r < b.r : a.point > b.point);
}

bool comp_score(Ball a, Ball b) {
    return
        score[a.id] != score[b.id] ?
        score[a.id] > score[b.id] :
        a.r < b.r;
}

bool comp_rad(Ball a, Ball b) {
    return a.r < b.r;
}


struct Edge{
    int to;
    double c;
    ll d;
    // bool operator>(const Edge &right)const{
    //     return cost > right.cost;
    // }
};

bool f (double dx, double dy, double dz, double sum_r) {
    return sqrt(dx*dx + dy*dy + dz*dz) >= sum_r;
}

int main(void){
    int L, N, M;
    cin >> L >> N >> M;
    vector<Ball> v(N), raw_v;
    vector<vector<Edge>> g(N);
    score.resize(N);
    rep(i,N) {
        double r;
        ll p;
        cin >> r >> p;
        v[i] = Ball(i, r, p);
        score[i] += p;
    }
    raw_v = v;
    
    rep(i,M) {
        int a,b,d;
        double c;
        cin >> a >> b >> c >> d;
        a--, b--;
        g[a].push_back({b,c,d});
        g[b].push_back({a,c,d});
        score[a] += d;
        score[b] += d;
    }

    sort(all(v), comp_point);
    // sort(all(v), comp_rad);
    // sort(all(v), comp_score);

    vector<int> X(N,-1), Y(N,-1), Z(N,-1);
    int rx = 0;
    int first_round = 0;
    rep(i,N) {
        int id = v[i].id;
        if (rx + v[i].r*2 > L) {
            first_round = i;
            break;
        }
        X[id] = rx + v[i].r;
        Y[id] = v[i].r;
        Z[id] = v[i].r;
        rx += v[i].r*2;
    }

    rx = 0;
    for (int i = first_round; i < N; i++) {
        int id = v[i].id;
        if (rx + v[i].r*2 > L) {
            first_round = i;
            break;
        }

        // check
        bool ng = false;
        int x = rx + v[i].r;
        int y = L - v[i].r;
        int z = L - v[i].r;
        rep(j,N) {
            if (X[j] == -1) continue;
            if (!f(x-X[j], y-Y[j], z-Z[j], raw_v[j].r + v[i].r)) {
                ng = true;
                break;
            }
        }
        if (ng) continue;
        X[id] = x;
        Y[id] = y;
        Z[id] = z;
        rx += v[i].r*2;
    }

    rep(i,N) {
        cout << X[i] << " " << Y[i] << " " << Z[i] << endl;
    }

    return 0;
}
