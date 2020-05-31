#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int n;

void rec(int pos, string s) {
    if (pos == n) {
        cout << s << endl;
        return;
    }
    int mx = -1;
    rep(i,pos) mx = max(mx, s[i] - 'a');
    rep(k,mx+2) rec(pos+1, s + char('a'+k));
}

int main(void){
    cin >> n;
    rec(0, "");
    return 0;
}
