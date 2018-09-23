#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

using P = pair<int,int>;
int n;

int dfs(vector<int> &won,vector<int> &lost,vector<P> &vp,int depth){
    if(depth == (int)vp.size()){
        int w = won[0];
        rep(i,n){
            if(won[i] != w) return 0;
        }
        return 1;
    }
    rep(i,n){
        if(won[i]  > n/2) return 0;
        if(lost[i] > n/2) return 0;
    }

    int x = vp[depth].first;
    int y = vp[depth].second;
    int res = 0;
    rep(_,2){
        won[x]++, lost[y]++;
        res += dfs(won,lost,vp,depth+1);
        won[x]--, lost[y]--;
        swap(x,y);
    }
    return res;
}

int main(void){
    while(cin>>n, n){
        int table[9][9] = {};
        int m;
        cin>>m;
        vector<int> won(n),lost(n);
        rep(i,m){
            int x,y;
            cin>>x>>y;
            x--,y--;
            won[x]++, lost[y]++;
            table[x][y] = +1;
            table[y][x] = -1;
        }
        vector<P> vp;
        rep(i,n)rep(j,i){
            if(table[i][j] == 0) vp.push_back(P(i,j));
        }
        cout<<dfs(won,lost,vp,0)<<endl;
    }
}
