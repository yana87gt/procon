#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 1;
    ll res = 0;
    rep(i,n){
        int idx = n-1-i;
        if(s[idx]=='B'){
            res += (n-cnt) - idx;
            cnt++;
        }
    }
    cout << res << endl;
    return 0;
}
