#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int n,D;
int c[1001][1001];
#define debug(x) cerr<<(#x)<<": "<<(x)<<endl


bool check(int a, int b) {
    int B[1000][1000] = {};
    rep(y,D) rep(x,D) {
        if (y <= b && x <= b)
            B[y][x] = (a+1)*(a+1);
        else if (b < y && b < x)
            B[y][x] = a*a;
        else B[y][x] = a*(a+1);
    }

    rep(oy,D) rep(ox,D) {
        bool ok = true;
        rep(y,D) rep(x,D) {
            if (c[x][y] > B[(y+D-oy)%D][(x+D-ox)%D])
                ok = false;
        }
        if (ok) return true;
    }
    return false;
}

int main(void){
    cin >> n >> D;
    int cnt_max = 0;
    rep(i,n) {
        int x,y;
        cin >> x >> y;
        c[x%D][y%D]++;
        cnt_max = max(c[x%D][y%D], cnt_max);
    }
    int a = 0;
    while (cnt_max > (a+1)*(a+1)) a++;

    int l = -1, r = D-1;
    while (l + 1 < r) {
        int b = (l+r)/2;
        if (check(a,b)) r = b;
        else l = b;
    }
    cout << a*D+r << endl;

    return 0;
}
