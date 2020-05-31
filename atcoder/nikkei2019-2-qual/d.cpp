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
const ll INF = 1e16;

#define debug(x) cerr<<(#x)<<": "<<(x)<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }


struct Event{
    ll l,r,cost;
    bool operator>(const Event &right)const{
        return l > right.l;
    }
};
using P = pair<ll,ll>;

int main(void){
    ll n,m;
    cin >> n >> m;
    priority_queue<Event,vector<Event>,greater<Event>> eventQ;
    priority_queue<P,vector<P>,greater<P>> paths;
    rep(i,m){
        ll l,r,c;
        cin >> l >> r >> c;
        eventQ.push({l,r,c});
    }

    paths.push({0,1});
    paths.push({INF,n+1});
    while(eventQ.size()){
        Event e = eventQ.top(); eventQ.pop();
        while(paths.top().second < e.l) paths.pop();
        paths.push({paths.top().first + e.cost, e.r});
    }
    while(paths.top().second < n) paths.pop();
    cout << ((paths.top().first < INF) ? paths.top().first : (ll)-1) << endl;

    return 0;
}
