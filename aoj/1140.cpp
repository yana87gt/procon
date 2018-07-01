#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define INF 1e9
using P = pair<int,int>;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<vector<int>> cost_map(
    int Y,int X,int sy,int sx,
    vector<string> &s){

    vector<vector<int>> cost(Y, vector<int>(X,INF));
    cost[sy][sx] = 0;
    queue<P> qu;
    qu.push(P(sy,sx));
    while(qu.size()){
        P p = qu.front(); qu.pop();
        int y = p.first;
        int x = p.second;
        rep(i,4){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(nx<0 || ny<0 || nx>=X || ny>=Y) continue;
            if(s[ny][nx] == 'x') continue;
            if( cost[ny][nx] > cost[y][x] + 1){
                cost[ny][nx] = cost[y][x] + 1;
                qu.push(P(ny, nx));
            }
        }
    }
    return cost;
}

int main(void){
    int Y,X;
    while(cin>>X>>Y, Y|X){
        vector<string> s(Y);
        rep(y,Y) cin>>s[y];
        vector<P> pos;
        rep(y,Y)rep(x,X){
            if(s[y][x]=='o' || s[y][x]=='*'){
                pos.push_back(P(y,x));
            }
        }
        int n = pos.size();
        int d[11][11];
        bool ng = false;
        rep(i,n){
            int y = pos[i].first;
            int x = pos[i].second;
            auto cost = cost_map(Y,X,y,x,s);
            rep(j,n){
                int ny = pos[j].first;
                int nx = pos[j].second;
                d[i][j] = cost[ny][nx];
                if(d[i][j] == INF) ng = true;
            }
        }
        if(ng){
            cout<<-1<<endl;
            continue;
        }
        vector<int> perm(n);
        rep(i,n) perm[i] = i;
        int res = INF;
        do{
            int sy = pos[perm[0]].first;
            int sx = pos[perm[0]].second;
            if(s[sy][sx] != 'o') continue;
            int cost = 0;
            rep(i,n-1){
                cost += d[perm[i]][perm[i+1]];
            }
            res = min(res, cost);
        }while(next_permutation(all(perm)));
        cout<<res<<endl;
    }
    return 0;
}
