#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

bool check(string s){
    int n = s.size();
    rep(i,n){
        if (s[i] != s[n-1-i]) return false;
    }
    return true;
}

int main(void){
    string s;
    cin >> s;
    int n = s.size();
    bool b1 = check(s);
    bool b2 = check(s.substr(0, (n-1)/2));
    bool b3 = check(s.substr((n+3)/2-1, n-(n+3)/2+1));
    cout << ((b1 && b2 && b3) ? "Yes" : "No") << endl;
    return 0;
}
