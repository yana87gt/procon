#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

ll nC2(ll n){
    return n*(n-1)/2;
}

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    map<ll,ll> cnt;
    rep(i,n) cnt[a[i]]++;
    ll allC = 0;
    for (auto itr : cnt){
        allC += nC2(itr.second);
    }
    rep(i,n){
        cout << allC - nC2(cnt[a[i]]) + nC2(cnt[a[i]]-1) << endl;
    }
    return 0;
}
