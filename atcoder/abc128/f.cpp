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

vector<int> divs(int n) {
    vector<int> res;
    rep1(i,sqrt(n)){
        if (n%i == 0) {
            res.push_back(i);
            if (n/i > i) {
                res.push_back(n/i);
            }
        }
    }
    return res;
}

int main(void){
    int n;
    cin >> n;
    vector<ll> s(n);
    rep(i,n) cin >> s[i];
    for(int a = 2; a < n; a++){
        auto bs = divs(n-1-a);
        for (int b: bs){
            if (n-1-a < a-b) continue;
            while(n-1) {

            }
        }
    }
    return 0;
}
