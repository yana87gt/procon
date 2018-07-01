#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

int digit_sum(ll x){
    int res = 0;
    while(x){
        res += x%10;
        x /= 10;
    }
    return res;
}

using P = pair<double,ll>;

int main(void){
    int k;
    cin>>k;
    vector<P> v;
    rep(d,15){
        ll pow10 = pow(10,d);
        rep(i,1000){
            ll x = pow10-1 + i*pow10;
            v.push_back({(double)x/digit_sum(x), x});
        }
    }
    sort(all(v));
    ll max = 0;
    int cnt = 0;
    for(P p : v){
        ll x = p.second;
        if(max >= x) continue;
        max = x;
        cout<<x<<endl;
        cnt++;
        if(cnt == k)break;
    }

    return 0;
}
