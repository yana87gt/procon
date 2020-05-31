#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

vector<vector<int>> g;
vector<int> st[3];

void coloring(int cur, int pre, bool col){
    // col = 0 or 1
    st[col].push_back(cur);
    for(int to : g[cur]) {
        if (to == pre) continue;
        coloring(to, cur, !col);
    }
}

int main(void){
    int n;
    cin >> n;
    g.resize(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    coloring(0, -1, true);

    if (st[0].size() < st[1].size()) {
        swap(st[0], st[1]);
    }

    if ((int)st[1].size() < (n+1)/3) {
        swap(st[1], st[2]);
        rep(i,(n+1)/3){
            st[1].push_back(st[0].back());
            st[0].pop_back();
        }
    }
    while((int)st[0].size() > (n+2)/3) {
        st[2].push_back(st[0].back());
        st[0].pop_back();
    }
    while((int)st[1].size() > (n+1)/3) {
        st[2].push_back(st[1].back());
        st[1].pop_back();
    }
    vector<int> p(n);
    rep(col, 3){
        rep(i, st[col].size()){
            p[st[col][i]] = i*3 + col + 1;
        }
    }
    rep(i,n){
        cout << p[i] << (i < n-1 ? " " : "\n");
    }
    return 0;
}
