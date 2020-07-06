#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define bit(k) (1LL<<(k))

int main(void) {
    int Y, X, K;
    cin >> Y >> X >> K;
    vector<string> s(Y);
    rep(y,Y) cin >> s[y];
    int res = 0;
    rep(maskY, 1<<Y)rep(maskX, 1<<X){
        int cnt = 0;
        rep(y,Y)rep(x,X){
            if (maskY & bit(y)) continue;
            if (maskX & bit(x)) continue;
            if (s[y][x] == '#') cnt++;
        }
        if (cnt == K) res ++;
    }
    cout << res << endl;
    return 0;
}
