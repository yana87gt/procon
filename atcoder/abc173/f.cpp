#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void) {
    ll n;
    cin >> n;
    ll edge_sum = 0;
    rep(i,n-1){
        ll u,v;
        cin >> u >> v;
        if (u>v) swap(u,v);
        edge_sum += u * (n-v+1);
    }
    ll ver_sum = 0;
    rep(i,n){
        ll v = i+1;
        ver_sum += v * (n-v+1);
    }
    cout << ver_sum - edge_sum << endl;
    return 0;
}
