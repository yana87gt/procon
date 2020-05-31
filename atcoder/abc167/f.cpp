#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

struct v {
    int down, up;
};

bool solve() {
    int n;
    cin >> n;
    vector<v> a, b;
    rep(i,n) {
        string s;
        cin >> s;
        int m = s.size();
        int h = 0;
        int down = 0;
        rep(j,m) {
            if (s[j] == '(') {
                h++;
            } else {
                h--;
            }
            down = min(down, h);
        }
        int up = h - down;
        down = abs(down);
        if (down < up) {
            a.push_back({down, up});
        } else {
            b.push_back({down, up});
        }
    }
    sort(all(a), [](v lhs, v rhs) {
        if (lhs.down != rhs.down) return lhs.down < rhs.down;
        else return lhs.up > rhs.up;
    });
    sort(all(b), [](v lhs, v rhs) {
        if (lhs.up != rhs.up) return lhs.up > rhs.up;
        else return lhs.down > rhs.down;
    });
    int h = 0;
    rep(i,a.size()){
        h -= a[i].down;
        if (h < 0) return false;
        h += a[i].up;
    }
    rep(i,b.size()){
        h -= b[i].down;
        if (h < 0) return false;
        h += b[i].up;
    }
    return h == 0;
}

int main(void){
    cout << ((solve()) ? "Yes" : "No") << endl;
    return 0;
}
