#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
using ll = long long;

string s[410];
int Y, X;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void calc(int y, int x, ll &black, ll &white, char pre) {
    if (y < 0 || x < 0 || x>=X || y>=Y) return;
    if (s[y][x] == '!' || s[y][x] == pre) return;
    if (s[y][x] == '#') black++;
    if (s[y][x] == '.') white++;
    char cur = s[y][x];
    s[y][x] = '!';
    rep(i,4){
        calc(y+dy[i], x+dx[i], black, white, cur);
    }
}

int main(void){
    cin >> Y >> X;
    rep(y,Y) cin >> s[y];

    ll res = 0;
    rep(y,Y) rep(x,X){
        ll black = 0;
        ll white = 0;
        calc(y, x, black, white, '!');
        res += black * white;
    }
    cout << res << endl;
    return 0;
}
