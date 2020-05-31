#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin >> s;
    int n = s.size();
    rep(i,n){
        if (s[i] == '?') {
            s[i] = 'D';
        }
    }
    cout << s << endl;
    return 0;
}
