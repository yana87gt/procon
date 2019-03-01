#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

struct Point{
    int x,y,h;
};

int main(void){
    int n;
    cin>>n;
    vector<Point> vp(n);
    int tall = -1;
    rep(i,n){
        int x,y,h;
        cin>>x>>y>>h;
        vp[i] = Point{x,y,h};
        if (h > 0) tall = i;
    }
    assert(tall>=0);
    rep(x,101)rep(y,101){
        int h = abs(vp[tall].x-x) + abs(vp[tall].y-y) + vp[tall].h;
        bool ng = false;
        rep(i,n){
            if (vp[i].h != max(h - abs(vp[i].x-x) - abs(vp[i].y-y), 0)) {
                ng = true;
            }
        }
        if (!ng) {
            cout << x << " " << y << " " << h << endl;
            return 0;
        }
    }
    return 0;
}
