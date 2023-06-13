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
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
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

template <typename T>
class Imos2D{
  public:
    int Y,X;
    vector<vector<T>> s;

    Imos2D(){}
    ~Imos2D(){}
    Imos2D(int Y_, int X_): Y(Y_),X(X_) {
        s.resize(Y+1);
        rep(y,Y+1) s[y].resize(X+1);
    }

    void add(int y,int x,int h,int w,T v){
        s[y][x] += v;
        s[y][x+w] -= v;
        s[y+h][x] -= v;
        s[y+h][x+w] += v;
    }

    void simulate(){
        rep(y,Y)rep(x,X-1){
            s[y][x+1] += s[y][x];
        }
        rep(y,Y-1)rep(x,X){
            s[y+1][x] += s[y][x];
        }
    }
    vector<T>& operator[](std::size_t y) &{ return s[y]; }
};

int main(void) {
    int Y, X, N, M;
    cin >> Y >> X >> N >> M;
    vector<map<int,bool>> blockY(Y+2), blockX(X+2);
    rep(y,Y+2){
        blockY[y][0] = blockY[y][X+1] = 1;
        blockX[0][y] = blockX[X+1][y] = 1;
    }
    rep(x,X+2){
        blockY[0][x] = blockY[Y+1][x] = 1;
        blockX[x][0] = blockX[x][Y+1] = 1;
    }

    Imos2D<int> imos(Y+2,X+2);
    vector<pair<int,int>> a(N);
    rep(i,N) {
        int y, x;
        cin >> y >> x;
        a[i] = {y,x};
    }
    rep(i,M) {
        int y, x;
        cin >> y >> x;
        blockY[y][x] = blockX[x][y] = 1;
    }
    rep(i,N) {
        int y = a[i].first, x = a[i].second;
        {
            auto itr = blockX[x].lower_bound(y);
            int r = itr->first;
            --itr;
            int l = itr->first;
            imos.add(l+1, x, r-l-1, 1, 1);
        }
        {
            auto itr = blockY[y].lower_bound(x);
            int r = itr->first;
            --itr;
            int l = itr->first;
            imos.add(y, l+1, 1, r-l-1, 1);
        }
    }
    imos.simulate();
    int cnt = 0;
    rep1(y,Y)rep1(x,X){
        if (imos[y][x] >= 1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
