#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    string s;
    cin >> s;
    reverse(all(s));
    int n = s.size();
    ll res = 0;
    ll bc = 0;
    rep(i,n){
        if (s[i] == 'A') {
            res += bc;
            continue;
        }
        if (i == n-1) {
            continue;
        }
        if (s[i] == 'C' && s[i+1] == 'B') {
            bc++;
            i++;
            continue;
        }
        bc = 0;
    }
    cout << res << endl;
    return 0;
}
