#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> qu;
    vector<int> d(n,-1);
    d[0] = 0;
    qu.push(0);
    while(qu.size()) {
        int cur = qu.front();
        qu.pop();
        for(int to : g[cur]) {
            if (d[to] != -1) continue;
            d[to] = cur;
            qu.push(to);
        }
    }
    cout << "Yes" << endl;
    rep1(i,n-1){
        cout << d[i] + 1 << endl;
    }
    return 0;
}
