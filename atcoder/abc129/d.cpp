#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

#define M 2010
int sumL[M][M] = {};
int sumR[M][M] = {};
int sumU[M][M] = {};
int sumD[M][M] = {};

int main(void){
    int Y,X;
    cin >> Y >> X;
    vector<string> s(Y);
    rep(y,Y) cin >> s[y];

    rep(yy,Y){
        int cnt = 0;
        rep(xx,X){
            int y = yy, x = xx;
            if (s[y][x] == '#') cnt = 0;
            else {
                sumL[y][x] = cnt;
                cnt++;
            }
        }
    }

    rep(yy,Y){
        int cnt = 0;
        rep(xx,X){
            int y = yy, x = X - 1 - xx;
            if (s[y][x] == '#') cnt = 0;
            else {
                sumR[y][x] = cnt;
                cnt++;
            }
        }
    }

    rep(xx,X){
        int cnt = 0;
        rep(yy,Y){
            int y = yy, x = xx;
            if (s[y][x] == '#') cnt = 0;
            else {
                sumD[y][x] = cnt;
                cnt++;
            }
        }
    }

    rep(xx,X){
        int cnt = 0;
        rep(yy,Y){
            int y = Y - 1 - yy, x = xx;
            if (s[y][x] == '#') cnt = 0;
            else {
                sumU[y][x] = cnt;
                cnt++;
            }
        }
    }
    int res = 0;
    rep(y,Y)rep(x,X){
        if (s[y][x] == '.') {
            res = max(res, 1 + sumL[y][x] + sumR[y][x] + sumD[y][x] + sumU[y][x]);
        }
    }
    cout << res << endl;

    return 0;
}
