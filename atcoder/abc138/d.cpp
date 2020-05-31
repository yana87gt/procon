#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

vector<int> g[200010];
ll cnt[200010];

void dfs(int cur, int par, ll cost){
    cnt[cur] += cost;
    for (int to : g[cur]) {
        if (to == par) continue;
        dfs(to, cur, cnt[cur]);
    }
}

int main(void){
    int n, q;
    cin >> n >> q;
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,q){
        int p,x;
        cin >> p >> x;
        p--;
        cnt[p] += x;
    }
    dfs(0, -1, 0);
    rep(i,n){
        cout << cnt[i] << (i < n-1 ? " " : "\n");
    }
    return 0;
}
