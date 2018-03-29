#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef pair<ll,ll> pll;

ll calc(pll p,ll i){
    return p.first + (p.second-i)*(p.second-i);
}

vector<ll> solve(int n,vector<ll> a){
    vector<ll> res(n);
    vector<pll> pre; // <aj, j>
    rep(i,n){
        ll mn = calc({a[i],i},i);
        vector<pll> cur;
        cur.push_back({a[i],i});
        for(auto p : pre){
            if(mn > calc(p,i)){
                mn = calc(p,i);
                cur.push_back(p);
            }
        }
        res[i] = mn;
        pre = cur;
    }
    return res;
}

int main(void){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    vector<ll> res1 = solve(n,a);
    reverse(all(a));
    vector<ll> res2 = solve(n,a);
    reverse(all(res2));
    rep(i,n){
        cout<<min(res1[i],res2[i])<<endl;
    }
    return 0;
}
