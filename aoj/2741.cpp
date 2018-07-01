#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int INF = 1001001001;

int n, m;
vector<int> a, b;

map<vector<int>,int> dp;
int dfs(int i, int j, int s, int p, int pc)
{
    vector<int> st = {i,j,s,p,pc};
    if (dp.count(st)) return dp[st];
    int res = -INF;
    {
        int ni = i, nj = j;
        if (p)nj++;
        else ni++;
        if (ni <= n && nj <= m) res = max(res, -dfs(ni,nj,s+1,p^1,0));
    }
    {
        int score = 0;
        int np = p^1, ni = i, nj = j;
        int si = 0, sj = 0;
        rep(k,s){
            if (np){
                --nj;
                if (b[nj] == -1)si = 1;
                else if (!sj) score -= b[nj];
            }else{
                --ni;
                if (a[ni] == -1)sj = 1;
                else if (!si) score += a[ni];
            }
            np ^= 1;
        }
        if (p) score = -score;
        if (pc && !s)res = max(res, 0);
        else res = max(res, -dfs(i,j,0,p^1,!s)+score);
    }
    return dp[st] = res;
}

int main() {
    cin >> n >> m;
    a = vector<int>(n);
    b = vector<int>(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    cout<<dfs(0,0,0,0,0)<<endl;
    return 0;
}
