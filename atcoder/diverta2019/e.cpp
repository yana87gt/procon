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


// void rec(int index, vector<bool> &div, vector<ll> &cum){
//     div[index] = true;
//     rec(index+1, div, cum);
//     div[index] = false;
//     rec(index+1, div, cum);
// }

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> cum(n+1);
    rep(i,n) {
        cin >> a[i];
        cum[i+1] = cum[i]^a[i];
    }
    if (cum[n] == 0) {
        
    } else {
        
    }
    print(cum);

    return 0;
}
