#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> h(n+1);
    rep(i,n){
        if (s[i] == '<') {
            h[i+1] = h[i] + 1;
        } else {
            h[i+1] = 0;
        }
    }
    rep(j,n){
        int i = n-1-j;
        if (s[i] == '>') {
            h[i] = max(h[i+1] + 1, h[i]);
        }
    }
    ll sum = 0;
    rep(i,n+1){
        sum += h[i];
    }
    cout << sum << endl;
    return 0;
}
