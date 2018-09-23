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


int main(void){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
    }

    vector<ll> med;
    // [l,r)
    rep(r,n+1)rep(l,r){
        printf("[l,r) = [%d,%d)\n", l,r);
        vector<ll> v;
        for(int i = l; i < r; i++){
            cout<<a[i]<<" ";
            v.push_back(a[i]);
        }
        cout<<endl;

        sort(all(v));
        med.push_back(v[v.size()/2]);
        cout<<"med: "<<med.back()<<endl;
        cout<<"---------------"<<endl;
    }
    sort(all(med));

    cout<<med[med.size()/2]<<endl;
        for(ll x : med){
            cout<<x<<" ";
        }
        cout<<endl;
    return 0;
}
