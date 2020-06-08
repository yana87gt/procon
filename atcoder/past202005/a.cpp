#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s,t;
    cin >> s >> t;
    if (s == t) {
        cout << "same" << endl;
    } else {
        bool ng = false;
        rep(i,3) {
            if (tolower(s[i]) != tolower(t[i])) ng = true;
        }
        cout << ((ng) ? "different" : "case-insensitive") << endl;
    }
    return 0;
}
