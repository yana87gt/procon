#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int Y,X;
    cin >> Y >> X;
    vector<string> s(Y);
    vector<int> cnt(X);
    rep(y,Y) {
        cin >> s[y];
        rep(x,X){
            if (s[y][x] == '#') {
                cnt[x]++;
            }
        }
    }
    rep(y,Y){
        if (count(all(s[y]), '#') == 0) {
            continue;
        }
        rep(x,X){
            if (cnt[x] == 0) continue;
            cout << s[y][x];
        }
        cout << endl;
    }
    return 0;
}
