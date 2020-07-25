#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
#define INF int(1e9)

struct Point
{
    ll x,y;
    char dir;
    bool operator<(const Point &rhs) const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<Point> vp(n);
    map<ll, set<Point>> sub_DR, sub_UL, add_LD, add_UR, ver_U, ver_D, hor_L, hor_R;
    rep(i,n) {
        Point p;
        cin >> p.x >> p.y >> p.dir;
        vp[i] = p;
        sub_DR[p.y - p.x].insert(p);
        sub_UL[p.y - p.x].insert(p);
        add_LD[p.y + p.x].insert(p);
        add_UR[p.y + p.x].insert(p);
        if (p.dir == 'U') ver_U[p.x].insert(p);
        if (p.dir == 'D') ver_D[p.x].insert(p);
        if (p.dir == 'L') hor_L[p.y].insert(p);
        if (p.dir == 'R') hor_R[p.y].insert(p);
    }

    ll res = INF;
    for (auto itr : sub_DR) {
        set<Point> &line = itr.second;
        Point pre = {0,0,'?'};
        for (auto &p : line) {
            if (pre.dir == 'R' && p.dir == 'D') {
                res = min(res, abs(pre.x-p.x) * 10);
            }
            pre = p;
        }
    }

    for (auto itr : sub_UL) {
        set<Point> &line = itr.second;
        Point pre = {0,0,'?'};
        for (auto &p : line) {
            if (pre.dir == 'U' && p.dir == 'L') {
                res = min(res, abs(pre.x-p.x) * 10);
            }
            pre = p;
        }
    }

    for (auto itr : add_LD) {
        set<Point> &line = itr.second;
        Point pre = {0,0,'?'};
        for (auto &p : line) {
            if (pre.dir == 'D' && p.dir == 'L') {
                res = min(res, abs(pre.x-p.x) * 10);
            }
            pre = p;
        }
    }

    for (auto itr : add_UR) {
        set<Point> &line = itr.second;
        Point pre = {0,0,'?'};
        for (auto &p : line) {
            if (pre.dir == 'R' && p.dir == 'U') {
                res = min(res, abs(pre.x-p.x) * 10);
            }
            pre = p;
        }
    }

    for (auto itr : ver_U) {
        ll k = itr.first;
        if (ver_D.find(k) == ver_D.end()) continue;
        set<Point> &line = itr.second;
        for (auto &p : line) {
            auto lb = ver_D[k].lower_bound(p);
            if (lb == ver_D[k].end()) break;
            res = min(res, abs(p.y - lb->y) * 5);
        }
    }

    for (auto itr : hor_R) {
        ll k = itr.first;
        if (hor_L.find(k) == hor_L.end()) continue;
        set<Point> &line = itr.second;
        for (auto &p : line) {
            auto lb = hor_L[k].lower_bound(p);
            if (lb == hor_L[k].end()) break;
            res = min(res, abs(p.x - lb->x) * 5);
        }
    }
    if (res == INF) {
        cout << "SAFE" << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}
