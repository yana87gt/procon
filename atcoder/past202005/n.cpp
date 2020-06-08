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

#define debug(x) cerr<<(#x)<<": "<<(x)<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

int main(void){
    int n,Q;
    cin >> n >> Q;
    vector<int> a(n+1);
    rep(i,n+1) a[i] = i;
    rep(q,Q){
        int t,x,y;
        cin >> t >> x >> y;
        if (t == 1) {
            swap(a[x],a[x+1]);
        } else {
            sort(a.begin()+x, a.begin()+y+1);
        }
    }
    rep1(i,n){
        cout << a[i] << (i < n ? " " : "\n");
    }
    return 0;
}
