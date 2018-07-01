#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int dfs(vector<pair<int,int>> &g, int v){
    if(g[v].first == 0 || g[v].second == 0) return 1;
    return 1 + min(dfs(g,g[v].first), dfs(g,g[v].second));
}

int main(void){
    int N;
    while(cin>>N){
        vector<pair<int,int>> g(N+1);
        rep1(i,N){
            int l,r;
            cin>>l>>r;
            g[i] = {l,r};
        }
        cout<<dfs(g,1)<<endl;
    }
    return 0;
}
