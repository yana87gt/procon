#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e9

int n;
string s;
vector<int> g[2000];

struct T { int L, R, num; };

T dfs(int cur, int par) {
    int sumR = 0, num = 0, maxL = 0, maxL_R = 0;
    for (int to : g[cur]) if (par != to) {
        T ch = dfs(to, cur);
        sumR += ch.R;
        num += ch.num;
        if ((maxL < ch.L) || (maxL == ch.L && maxL_R > ch.R)) {
            maxL = ch.L;
            maxL_R = ch.R;
        }
    }
    if (s[cur] == '1') num++;
    return { max(0, maxL - (sumR - maxL_R)) + num, sumR + num, num };
}

int main(void){
    cin >> n >> s;
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int res = INF;
    rep(root, n){
        T t = dfs(root, -1);
        if (t.L == t.num && (t.R - t.num)%2 == 0) {
            res = min(res, (t.R - t.num)/2);
        }
    }
    cout << (res < INF ? res : -1) << endl;

    return 0;
}
