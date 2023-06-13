#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

#define Y 18
#define X 6
ll dp[Y+2][1<<(X+1)][1<<(X+1)] = {};

int main(void) {
    vector<string> s(Y+2);
    s[0] = s[Y+1] = string(X+2, '0');
    rep1(y,Y) {
        cin >> s[y];
        s[y] = "0" + s[y] + "0";
    }
    auto check01 = [&](int y, int mask) {
        rep1(x,X) {
            if (((mask>>x & 1) == 0) && s[y][x] == '1') return false;
            if (((mask>>x & 1) == 1) && s[y][x] == '0') return false;
        }
        return true;
    };
    rep(mask, 1<<(X+1)) if (((mask & 1) == 0) && check01(1,mask)) {
        dp[0][0][mask] = 1;
    }
    rep1(y,Y) {
        rep(mask1, 1<<(X+1)) if (((mask1 & 1) == 0) && check01(y-1, mask1)) {
            rep(mask2, 1<<(X+1)) if (((mask2 & 1) == 0) && check01(y, mask2)) {
                rep(mask3, 1<<(X+1)) if (((mask3 & 1) == 0) && check01(y+1, mask3)) {
                    bool ok = true;
                    rep1(x,X) {
                        int vals[] = {(mask1>>x)&1, (mask2>>(x-1))&1, (mask2>>x)&1, (mask2>>(x+1))&1, (mask3>>x)&1};
                        sort(vals, vals+5);
                        if (vals[2] != ((mask2>>x)&1)) ok = false;
                    }
                    if (ok) dp[y][mask2][mask3] += dp[y-1][mask1][mask2];
                }
            }
        }
    }
    ll res = 0;
    rep(mask, 1<<(X+1)) {
        res += dp[Y][mask][0];
    }
    cout << res << endl;
    return 0;
}
