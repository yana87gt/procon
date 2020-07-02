#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    ll n;
    cin >> n;
    vector<ll> cnt(n+1);
    ll res = 0;
    rep1(i,n){
        rep1(j,n){
            if (i*j > n) break;
            cnt[i*j]++;
        }
        res += i * cnt[i];
    }
    cout << res << endl;
    return 0;
}
