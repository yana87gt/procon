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


int main(void){
    int n,m;
    cin >> n >> m;
    vector<int> imos(n+2);
    rep(i,m){
        int l,r;
        cin >> l >> r;
        imos[l]++;
        imos[r+1]--;
    }
    int cnt = 0;
    rep1(i,n){
        imos[i+1] += imos[i];
        if (imos[i]>=m) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
