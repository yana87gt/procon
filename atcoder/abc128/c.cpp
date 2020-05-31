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
    int n, m;
    cin >> n >> m;
    vector<int> s[10];
    rep(i,m){
        int k;
        cin >> k;
        s[i].resize(k);
        rep(j,k){
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    vector<int> p(m);
    rep(i,m){
        cin >> p[i];
    }
    int res = 0;
    rep(mask, 1<<n){
        bool ok = true;
        rep(i,m){
            int cnt = 0;
            rep(j,s[i].size()){
                if(mask & (1<<s[i][j])) cnt++;
            }
            if (cnt%2 != p[i]) ok = false;
        }
        if(ok) res++;
    }
    cout << res << endl;
    return 0;
}
