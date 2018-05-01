#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

ll n,c;

ll solve(vector<ll> x,vector<ll> v){
    vector<ll> rt(n+1);
    ll sumV = 0;
    rep(i,n){
        sumV += v[i];
        rt[i+1] = max(rt[i], sumV-x[i]*2);
    }

    sumV = 0;
    ll res = 0;
    for(int i = n-1; i >= 0; i--){
        sumV += v[i];
        res = max((sumV-(c-x[i])) + rt[i], res);
    }

    return res;
}

int main(void){
    cin>>n>>c;
    vector<ll> x(n),v(n);
    rep(i,n) cin>>x[i]>>v[i];
    
    ll res1 = solve(x,v);

    reverse(all(x));
    reverse(all(v));
    rep(i,n) x[i] = c-x[i];
    ll res2 = solve(x,v);

    cout<<max(res1,res2)<<endl;
    return 0;
}
