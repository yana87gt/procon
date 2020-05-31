#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))

vector<vector<int>> g;

bool get_path(int cur, int pre, int goal, vector<int> &path){
    static map<pair<int,int>, int> path_id;
    if (cur == goal) return true;
    for(int to : g[cur]){
        if(to == pre) continue;
        pair<int,int> p = {min(cur, to), max(cur, to)};
        int id = path_id.count(p) ? path_id[p] : path_id.size();
        path_id[p] = id;
        path.push_back(id);
        if (get_path(to, cur, goal, path)) {
            return true;
        } else {
            path.pop_back();
        }
    }
    return false;
}

int main(void){
    int n;
    cin >> n;
    g.resize(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int m;
    cin >> m;
    vector<vector<int>> paths(m);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        get_path(u, -1, v, paths[i]);
    }
    long long res = 0;
    rep(mask, 1<<m){
        vector<bool> on(n);
        rep(i,m){
            if (bit(i) & mask) {
                for(int e : paths[i]) {
                    on[e] = true;
                }
            }
        }
        res += (((int)__builtin_popcount(mask) & 1) ? -1 : +1) * (1LL<<((n-1)-count(all(on), true)));
    }
    cout << res << endl;
    return 0;
}
