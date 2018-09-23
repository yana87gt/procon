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

struct State{
    int y,x,dir;
};

struct Query{
    int sy,sx,gy,gx;
    char dir;
};

int dy = {+1,0,-1,0};
int dx = {0,+1,0,-1};

#define turnL(dir) ((dir+1)%4)
#define turnR(dir) ((dir+3)%4)

vector<string> s;

bool canGo(const State st){
    return s[st.y*2-1 + dy[st.dir]][st.x*2-1 + dx[st.dir]] == '.'
}

State go(State st){
    return (State){st.y+dy[st.dir], st.x+dx[st.dir], (dir+3)%4};
}

int main(void){
    int Y,X,Q;
    s.resize(Y*2+1);
    rep(y,Y*2+1){
        cin>>s[y];
    }
    vector<Query> query(Q);
    rep(q,Q){
        int sy,sx,gy,gx,dir;
        cin>>sy>>sx>>gy>>gx>>dir;
        query[q] = {sy,sx,gy,gx,dir};
    }
    State start = {1,1,0};
    State cur = start;
    do{
        // cur = ;
    }while(cur == start);
    return 0;
}
