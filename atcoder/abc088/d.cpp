#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

#define INF 1e9

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<string> s;
int d[60][60];

void dfs(int y,int x,int cost){
    if (s[y][x] == '#') return;
    if (d[y][x] > cost) {
        d[y][x] = cost;
        rep(i,4) dfs(y+dy[i],x+dx[i],cost+1);
    }
}

int main(void){
    int h,w;
    cin>>h>>w;
    s = vector<string>(h+2);
    s[0] = s[h+1] = string(w+2,'#');
    rep(y,h){
        string line;
        cin>>line;
        s[y+1] = "#"+line+"#";
    }
    int dot = 0;
    rep1(y,h)rep1(x,w){
        d[y][x] = INF;
        if(s[y][x] == '.') dot++;
    }
    dfs(1,1,1);
    cout<<(d[h][w] == INF ? -1 :dot-d[h][w])<<endl;
    return 0;
}
