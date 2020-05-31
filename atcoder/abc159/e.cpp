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

    void add(int y,int x,T v){
        s[y+1][x+1] += v;
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
    T get(int y, int x) {
        return s[y+1][x+1];
    }
    T get(int y1,int y2,int x1, int x2){
        return get(y2,x2) - get(y1,x2) - get(y2,x1) + get(y1,x1);
    }
};

int main(void){
    int Y, X, K; // Y <= 10
    cin >> Y >> X >> K;
    vector<string> s(Y);
    rep(y,Y) cin >> s[y];
    Imos2D<int> imos(Y,X);
    rep(y,Y){
        rep(x,X){
            imos.add(y,x, s[y][x] == '1');
        }
    }

    int res = Y*X;
    rep(y_mask,1<<(Y-1)){
        ll sum = __builtin_popcount(y_mask);
        int last_x = 0;
        int last_y = 0;
        rep(y,Y){
            (y_mask & bit(y))

        }
        rep(x,X){

        }
    }

    return 0;
}