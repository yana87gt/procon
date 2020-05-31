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


bool solve(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    {
        vector<int> ta = a, tb = b;
        sort(all(ta));
        sort(all(tb));
        rep(i,n){
            if (ta[i] > tb[i]) return false;
        }
    }

    // priority_queue<P,vector<P>,greater<P>> paths;
    using P = pair<int,int>;
    vector<P> v(n);
    multiset<int> remA;
    rep(i,n){
        v[i] = {b[i], a[i]};
        remA.insert(a[i]);
    }
    sort(all(v));
    int cnt = 0;
    rep(i,n){
        int ai = v[i].first;
        int bi = v[i].first;
        debug(__LINE__);
        remA.erase(remA.find(ai));
        debug(__LINE__);
        if (ai <= bi) continue;
        cnt++;
        debug(__LINE__);
        auto itr = remA.upper_bound(bi);
        debug(__LINE__);
        if (itr == remA.begin()) return false;
        debug(__LINE__);
        --itr;
        debug(__LINE__);
        remA.erase(itr);
        debug(__LINE__);
        remA.insert(ai);
        debug(__LINE__);
    }
    return cnt <= n-2;
}

int main(void){
    cout << ((solve()) ? "Yes" : "No") << endl;
    return 0;
}
