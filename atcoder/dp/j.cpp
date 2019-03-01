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

double dp[302][302][302];
bool done[302][302][302];
int n;
int sum[4];

double calc(int c1, int c2, int c3) {
    if (c3 > sum[3] || c1+c2+x3 > n) return 0;
    if (dp[c1][c2][c3]) return dp[c1][c2][c3];
    vector<double> v;
    if (c1+1 <= sum[0]) {
        double e = calc(c1+1, c2, c3);
        v.push_back()
    }
    return 0;
}

int main(void){
    rep(i,n) {
        int x;
        cin >> x;
        sum[x]++;
    }

    return 0;
}
