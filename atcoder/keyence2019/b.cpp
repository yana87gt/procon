#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin >> s;
    string t = "keyence";
    int n = s.size();
    int p = 0;
    rep(i,n){
        if (s[i] == t[p]) p++;
        else break;
    }
    cout << (s.substr(n-(7-p)) == t.substr(p) ? "YES" : "NO") << endl;
    return 0;
}
