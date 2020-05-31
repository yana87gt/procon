#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int Y, X;
int a[80][80];
int b[80][80];
#define M 80*80*80
bitset<M*2+1> bs[80][80] = {};

int delta(int y, int x){
    return abs(a[y][x]-b[y][x]);
}

int main(void){
    cin >> Y >> X;
    rep(y,Y)rep(x,X) cin >> a[y][x];
    rep(y,Y)rep(x,X) cin >> b[y][x];
    bs[0][0][M-delta(0,0)] = true;
    bs[0][0][M+delta(0,0)] = true;
    rep(y,Y)rep(x,X){
        if (y+1 < Y) {
            int d = delta(y+1,x);
            bs[y+1][x] |= (bs[y][x] << d) | (bs[y][x] >> d);
        }
        if (x+1 < X) {
            int d = delta(y,x+1);
            bs[y][x+1] |= (bs[y][x] << d) | (bs[y][x] >> d);
        }
    }
    rep(i,M+1){
        if (bs[Y-1][X-1][M-i] || bs[Y-1][X-1][M+i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
