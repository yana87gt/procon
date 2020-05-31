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

int N, W, K, V;

struct Mino
{
    unsigned char data;
    Mino(int col, int value){
        // 0 <= col <= 5 (3bit), 1 <= value <= 8 (4bit)
        data = (col << 4) | value;
    }
    inline int color() const {
        return data >> 4;
    }
    inline int value() const {
        return 0xf & data;
    }
};

struct State
{
    vector<vector<Mino>> blocks;
    int score;
    State(){
        score = 0;
        blocks.resize(W);
    }
    bool operator<(const State& rhs) const {
        // TODO:高さの調整
        return (score < rhs.score);
    }
};

int main(void){
    int N, W, K, V;
    cin >> N >> W >> K >> V;
    vector<int> c(N), v(N);
    rep(i,N) cin >> c[i] >> v[i];

    rep(i,N) {
        
    }
    return 0;
}
