#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
struct Point { int x,y; };
vector<Point> ps;
vector<vector<int>> g;
vector<bool> used;

void dfs(int cur, int &cnt, set<int> &xs, set<int> &ys) {
    if (used[cur]) return;
    cnt++;
    used[cur] = true;
    xs.insert(ps[cur].x);
    ys.insert(ps[cur].y);

    for(int to : g[cur]) {
        dfs(to, cnt, xs, ys);
    }
}

int main(void){
    int n;
    cin >> n;
    ps.resize(n);
    g.resize(n);
    used.resize(n);
    rep(i,n){
        int x,y;
        cin >> x >> y;
        ps[i] = {x,y};
    }

    vector<int> ord(n);
    iota(all(ord), 0);

    sort(all(ord), [&](int i, int j){
        return ps[i].x != ps[j].x ? ps[i].x < ps[j].x : ps[i].y < ps[j].y;
    });
    rep(i,n-1){
        if (ps[ord[i]].x == ps[ord[i+1]].x){
            g[ord[i]].push_back(ord[i+1]);
            g[ord[i+1]].push_back(ord[i]);
        }
    }

    sort(all(ord), [&](int i, int j){
        return ps[i].y != ps[j].y ? ps[i].y < ps[j].y : ps[i].x < ps[j].x;
    });
    rep(i,n-1){
        if (ps[ord[i]].y == ps[ord[i+1]].y){
            g[ord[i]].push_back(ord[i+1]);
            g[ord[i+1]].push_back(ord[i]);
        }
    }

    ll res = 0;
    rep(i,n){
        int cnt = 0;
        set<int> xs, ys;
        dfs(i, cnt, xs, ys);
        res += xs.size() * ys.size() - cnt;
    }
    cout << res << endl;
    return 0;
}
