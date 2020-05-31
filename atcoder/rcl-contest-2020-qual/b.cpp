#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define lb(s,x) (lower_bound(all(s),x)-s.begin())
#define ub(s,x) (upper_bound(all(s),x)-s.begin())
#define uniq(a) a.erase(unique(all(a)),a.end())
#define bit(k) (1LL<<(k))
const int INF = 1e9;

#define debug(x) cerr<<(#x)<<": "<<(x)<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }


int n, m;
int a[60][60] = {};
int b[60][60] = {};

struct Result
{
    int res_x, res_y, max_inc, min_dec;
};

Result draw_horizontal(int col){
    int min_dec = 0;
    int max_inc = 0;
    int res_x = 0;
    int res_y = 0;
    rep(y,n){
        rep(x,n){
            int inc = 0;
            int dec = 0;
            if (b[y][x] != col) continue;
            rep(i,5) {
                if (x+i >= n) continue;
                if (a[y][x+i] == col && b[y][x+i] != col) {
                    inc++;
                }
                if (a[y][x+i] != col && a[y][x+i] == b[y][x+i]) {
                    dec++;
                }
            }
            if (max_inc < inc || (max_inc == inc && min_dec > dec)) {
                res_x = x;
                res_y = y;
                max_inc = inc;
                min_dec = dec;
            }
        }
    }
    Result res = {res_y, res_x, max_inc, min_dec};
    return res;
}


Result draw_vertical(int col){
    int min_dec = 0;
    int max_inc = 0;
    int res_x = 0;
    int res_y = 0;
    rep(x,n){
        rep(y,n-4){
            int inc = 0;
            int dec = 0;
            if (b[y][x] != col) continue;
            rep(i,5) {
                if (y+i >= n) continue;
                if (a[y+i][x] == col && b[y+i][x] != col) {
                    inc++;
                }
                if (a[y+i][x] != col && a[y+i][x] == b[y+i][x]) {
                    dec++;
                }
            }
            if (max_inc < inc || (max_inc == inc && min_dec > dec)) {
                res_x = x;
                res_y = y;
                max_inc = inc;
                min_dec = dec;
            }
        }
    }
    Result res = {res_y, res_x, max_inc, min_dec};
    return res;
}

void output_horizontal(int y, int x, int col){
    cout << y << " " << x << " R" << endl;
    rep(i,5){
        if (x+i >= n) continue;
        b[y][x+i] = col;
    }
}

void output_vertical(int y, int x, int col){
    cout << y << " " << x << " D" << endl;
    rep(i,5){
        if (y+i >= n) continue;
        b[y+i][x] = col;
    }
}

int main(void){
    cin >> n >> m;
    rep(y,n){
        rep(x,n) cin >> a[y][x];
    }
    rep(y,n){
        rep(x,n) {
            b[y][x] = -1;
        }
    }
    b[0][0] = 0;
    b[0][n-1] = 1;
    b[n-1][0] = 2;
    b[n-1][n-1] = 3;

    rep(i,m){
        int col = i%4;
        Result res_hor = draw_horizontal(col);
        Result res_ver = draw_vertical(col);
        if (max(res_hor.max_inc, res_ver.max_inc) >= 3) {
            if (res_hor.max_inc > res_ver.max_inc) {
                output_horizontal(res_hor.res_y, res_hor.res_x, col);
            } else {
                output_vertical(res_hor.res_y, res_hor.res_x, col);
            }
        } else if (res_hor.max_inc > res_hor.min_dec) {
            output_horizontal(res_hor.res_y, res_hor.res_x, col);
        } else if (res_ver.max_inc > res_ver.min_dec) {
            output_vertical(res_ver.res_y, res_ver.res_x, col);
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
