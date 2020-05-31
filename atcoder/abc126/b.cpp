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
    int n;
    cin >> n;
    bool b1 = (n/100) <= 12 && (n/100) >= 1;
    bool b2 = (n%100) <= 12 && (n%100) >= 1;
    if (b1 && b2) {
        cout << "AMBIGUOUS" << endl;
    } else if (b1 && !b2) {
        cout << "MMYY" << endl;
    } else if (!b1 && b2) {
        cout << "YYMM" << endl;
    } else if (!b1 && !b2) {
        cout << "NA" << endl;
    }
    return 0;
}
