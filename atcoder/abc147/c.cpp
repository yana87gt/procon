#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define bit(k) (1LL<<(k))

int g[16][16] = {};

int main(void){
    int n;
    cin >> n;
    rep(i,n) rep(j,n) g[i][j] = -1;
    rep(i,n){
        int m;
        cin >> m;
        rep(j,m){
            int x,y;
            cin >> x >> y;
            g[i][x-1] = y;
        }
    }
    int res = 0;
    rep(mask, 1<<n){
        auto check = [&](){
            rep(i,n){
                if (!(bit(i) & mask)) continue;
                rep(j,n){
                    if(g[i][j] == 1){
                        if (!(bit(j) & mask)) {
                            return false;
                        }
                    }
                    if(g[i][j] == 0){
                        if ((bit(j) & mask)) {
                            return false;
                        }
                    }
                }
            }
            return true;
        };
        if(check()){
            res = max(res, __builtin_popcount (mask));
        }
    }
    cout << res << endl;
    return 0;
}
