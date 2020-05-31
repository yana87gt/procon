#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    vector<vector<string>> s(8);
    s[3] = {
        "aa.",
        "..b",
        "..b"
    };
    s[4] = {
        "aabd",
        "ffbd",
        "hgcc",
        "hgee"
    };
    s[5] = {
        "aabba",
        "bcc.a",
        "b..cb",
        "a..cb",
        "abbaa"
    };
    s[6] = {
        "aabc..",
        "ddbc..",
        "..aabc",
        "..ddbc",
        "bc..aa",
        "bc..dd"
    };
    s[7] = {
        "aabbcc.",
        "dd.dd.a",
        "..d..da",
        "..d..db",
        "dd.dd.b",
        "..d..dc",
        "..d..dc"
    };
    if (n == 2) {
        cout << -1 << endl;
    } else if (n <= 7) {
        rep(y,n) cout << s[n][y] << endl;
    } else {
        vector<string> t(n, string(n, '.'));
        int a = n/4-1;
        int b = n-a*4;
        rep(i,a)rep(y,4)rep(x,4) {
            t[i*4+y][i*4+x] = s[4][y%4][x%4];
        }
        rep(y,b)rep(x,b){
            t[a*4+y][a*4+x] = s[b][y][x];
        }
        rep(y,n) cout << t[y] << endl;
    }
    return 0;
}
