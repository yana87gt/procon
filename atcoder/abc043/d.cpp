#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin >> s;
    s += " ";
    int n = s.size();
    rep(i,n-2){
        if (s[i] == s[i+1]) {
            cout << i+1 << " " << i+2 << endl;
            return 0;
        }
        if (s[i] == s[i+2]) {
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}
