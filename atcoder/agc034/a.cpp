#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int n,a,b,c,d;
string s;

bool solve() {
    rep(i,n-1){
        if(s[i] == '#' && s[i+1] == '#'){
            if (a < i && i < c) return false;
            if (b < i && i < d) return false;
        }
    }
    if (c < d) return true;
    for (int i = b; i <= d; i++) {
        if (s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') return true;
    }
    return false;
}

int main(void){
    cin >> n >> a >> b >> c >> d;
    cin >> s;
    a--,b--,c--,d--;
    cout << ((solve()) ? "Yes" : "No") << endl;
    return 0;
}
